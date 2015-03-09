/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif


#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "fft.h"
#include "rna.h"

#include <dsp.h>

#include <stdio.h>
#include <math.h>
#include <time.h>

#define MUL13    13
#define ARRIBA                      LATBbits.LATB15
#define ABAJO                       LATBbits.LATB14
#define DERECHA 		    LATBbits.LATB13
#define IZQUIERDA                   LATBbits.LATB12

#define ENTRENAMIENTO   0
#define RECONOCIMIENTO  1

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

signed int voz[10000];
float carMFCC[624];
//fractcomplex sigCmpx[FFT_BLOCK_LENGTH];

extern fractcomplex sigCmpx[FFT_BLOCK_LENGTH] __attribute__ ((section (".ydata, data, ymemory"), aligned (FFT_BLOCK_LENGTH*2*2)));

unsigned int longitudComandoVoz, c, c2, filasMFCC;
clock_t start, stop;
signed int mayor, menor;

uint8_t vecesEscucha;
signed char salida;

extern const fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2]	/* Twiddle Factor array in Program memory */
__attribute__ ((space(auto_psv), aligned (FFT_BLOCK_LENGTH*2)));


//Neural Network Input Weights for A
extern const float IW[HIDDENLAYER][INPUTNEURONS] __attribute__ ((space(auto_psv)));

//Neural Network Layer Weights for Output
extern const float LW[OUTPUTNEURONS][HIDDENLAYER] __attribute__ ((space(auto_psv)));

//Neural Network bias
extern const float bias1[HIDDENLAYER] __attribute__ ((space(auto_psv)));
extern const float bias2[OUTPUTNEURONS] __attribute__ ((space(auto_psv)));

//Constantes del mapeo mapminmax
extern const float ps_rangex[INPUTNEURONS] __attribute__ ((space(auto_psv)));
extern const float ps_xmin[INPUTNEURONS] __attribute__ ((space(auto_psv)));

//Constantes de PCA: promedios y matriz de eigen valores y covarianzas
extern const float means[624] __attribute__ ((space(auto_psv)));
extern const float eigenCov[624][INPUTNEURONS] __attribute__ ((space(auto_psv)));

//hmFactors FFT_BLOCK_LENGTH 256
extern const fractional hmFactors1[6]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors2[7]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors3[8]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors4[9]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors5[11]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors6[13]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors7[15]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors8[18]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors9[22]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors10[26]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors11[30]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors12[36]
__attribute__ ((space(auto_psv)));
extern const fractional hmFactors13[43]
__attribute__ ((space(auto_psv)));


float round(float number);
unsigned int mfcc(unsigned int tamEntrada, unsigned int tamVentana, int solapamiento, float alfa);
unsigned int grabarComandoDeVoz(void);
void getPCAValues(float *salida);
void applyMapminmax(float *input);
signed char forwardPropagation(void);
float restaAbs(float a, float b);

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

unsigned int modo = RECONOCIMIENTO;

int16_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    configureUART();
    initADC();

    TRISAbits.TRISA1 = 0;

    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;

    LATAbits.LATA1 = 1;
    __delay_ms(2000);
    LATAbits.LATA1 = 0;
    __delay_ms(500);

    /*Imprimir valores del comando de voz para crear wav*/

    /*longitudComandoVoz = grabarComandoDeVoz();

    LATBbits.LATB0 = 1;

    c = 0;

    while(c<longitudComandoVoz)
    {
        printf("%d ", voz[c]);
        c++;
    }

    LATBbits.LATB0 = 0;

    while(1);*/

    /*Fin iImprimir valores del comando de voz para crear wav*/

    if(modo==ENTRENAMIENTO)
    {
        //Inicio entrenamiento
        for(c=0; c<15; c++)
        {
            printf("Extrayendo caracteristicas...\n");
            longitudComandoVoz = grabarComandoDeVoz();

            LATBbits.LATB0 = 1;

            filasMFCC = mfcc((longitudComandoVoz), 256, 128, 0.7);

            //Si el vector de caracteristicas es menos que 48 neuronas(normalizacion basada en el comando mas grande->IZQUIERDA)
            //se le complentan con 0's
            if(filasMFCC != 48)
            {
                for(c2=filasMFCC; c2<48; c2++)
                    printf("0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;");
                    //printf("0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 ");
            }

            printf("\nFin caracteristicas\n");

            LATBbits.LATB0 = 0;
        }
        while(1);
        //Fin Entrenamiento.
    }

    if(modo==RECONOCIMIENTO)
    {
        //Inicio reconocimiento
        for(vecesEscucha=0; vecesEscucha<30; vecesEscucha++)
        //while(1)
        {

            longitudComandoVoz = grabarComandoDeVoz();
            //LATBbits.LATB0 = 1;
            LATAbits.LATA1 = 1;

            //start = clock();
            filasMFCC = mfcc((longitudComandoVoz), 256, 128, 0.7);

            //printf("stop = %ld\n", stop);
            //Si el vector de caracteristicas es menos que 48 datos(normalizacion basada en el comando mas grande->IZQUIERDA)
            //se le complentan con 0's
            if(filasMFCC != 48)
            {
                for(c2=filasMFCC; c2<48; c2++)
                {
                    for(c=0; c<13; c++)
                    {
                        carMFCC[c2*MUL13+c] = 0.0;
                        //printf("0.0 ");
                        //printf("0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;");
                    }
                }
            }

        //printf("\nFin caracteristicas\n");

        //start = clock();
        salida = forwardPropagation();
        //printf("start = %ld\n", start);
        //printf("stop = %ld\n", stop);

        LATAbits.LATA1 = 0;

        if(salida==0) //ARRIBA
        {
            printf("%c", 'a');
            LATBbits.LATB0 = 1;
            LATBbits.LATB1 = 0;
            LATBbits.LATB2 = 0;
            LATBbits.LATB3 = 0;
        }
        else if(salida==1) //ABAJO
        {
            printf("%c", 'b');
            LATBbits.LATB0 = 0;
            LATBbits.LATB1 = 1;
            LATBbits.LATB2 = 0;
            LATBbits.LATB3 = 0;

        }
        else if(salida==2) //DERECHA
        {
            printf("%c", 'c');
            LATBbits.LATB0 = 0;
            LATBbits.LATB1 = 0;
            LATBbits.LATB2 = 1;
            LATBbits.LATB3 = 0;
        }
        else if(salida==3) //IZQUIERDA
        {
            printf("%c", 'd');
            LATBbits.LATB0 = 0;
            LATBbits.LATB1 = 0;
            LATBbits.LATB2 = 0;
            LATBbits.LATB3 = 1;
        }
        else if(salida==4) //PARA
        {
            printf("%c", 'g');
            LATBbits.LATB0 = 0;
            LATBbits.LATB1 = 0;
            LATBbits.LATB2 = 0;
            LATBbits.LATB3 = 0;

        }
        else if(salida==5) //ABRE
        {
            printf("%c", 'e');
            LATBbits.LATB0 = 1;
            LATBbits.LATB1 = 1;
            LATBbits.LATB2 = 0;
            LATBbits.LATB3 = 0;
        }
        else if(salida==6) //CIERRA
        {
            printf("%c", 'f');
            LATBbits.LATB0 = 0;
            LATBbits.LATB1 = 0;
            LATBbits.LATB2 = 1;
            LATBbits.LATB3 = 1;
        }

        }//Corchete bucle vecesEscucha
        //Fin Reconocimiento.
    }
    
}

unsigned int grabarComandoDeVoz(void)
{
    signed int tempADC;
    unsigned int longitud = 0;
    mayor=0;
    menor=0;

    do
    {
        AD1CON1bits.SAMP = 1; // Start sampling
        __delay_us(10); // Wait for sampling time (10 us)
        AD1CON1bits.SAMP = 0; // Start the conversion
        while (!AD1CON1bits.DONE); // Wait for the conversion to complete
        tempADC = ADC1BUF0<<4;

        /*RES_PIN_0 = ((ADC1BUF0>>8) & 0x01);
	RES_PIN_1 = ((ADC1BUF0>>8) & 0x02)>>1;
	RES_PIN_2 = ((ADC1BUF0>>8) & 0x04)>>2;
	RES_PIN_3 = ((ADC1BUF0>>8) & 0x08)>>3;*/

        __delay_us(130);//10 KHz
        //__delay_us(70);//16 KHz
    }while(tempADC<15000);
    //while(Fract2Float(tempADC)>(-0.9900f) && Fract2Float(tempADC)<(-0.5500f));

    //printf("%f\n", Fract2Float(tempADC));
    //printf("%d ", tempADC);

    //Mientras mas samples por segundo (menos __delay_us) se escucha mas grueso y lento
    do
    {
        AD1CON1bits.SAMP = 1; // Start sampling
        __delay_us(10); // Wait for sampling time (10 us)
        AD1CON1bits.SAMP = 0; // Start the conversion
        while (!AD1CON1bits.DONE); // Wait for the conversion to complete
        //voz[i] = ADC1BUF0<<3; // Read the ADC conversion result
        tempADC = ADC1BUF0<<4;
        voz[longitud] = tempADC; // Read the ADC conversion result
        longitud++;

        /*RES_PIN_0 = ((ADC1BUF0>>8) & 0x01);
	RES_PIN_1 = ((ADC1BUF0>>8) & 0x02)>>1;
	RES_PIN_2 = ((ADC1BUF0>>8) & 0x04)>>2;
	RES_PIN_3 = ((ADC1BUF0>>8) & 0x08)>>3;*/

        __delay_us(130);//10 KHz
        //__delay_us(70);

        if(mayor<(signed int)(ADC1BUF0<<4))
            mayor=(signed int)(ADC1BUF0<<4);
        if(menor>(signed int)(ADC1BUF0<<4))
            menor=(signed int)(ADC1BUF0<<4);
    }while(longitud<10000);

    do
    {
	longitud--;
        tempADC = voz[longitud];
    }while(tempADC<14000);
    //while(Fract2Float(tempADC)>(-0.9900f) && Fract2Float(tempADC)<(-0.5600f));

    /*RES_PIN_0 = 0;
    RES_PIN_1 = 0;
    RES_PIN_2 = 0;
    RES_PIN_3 = 0;*/

    //printf("%f->%u\n", Fract2Float(tempADC), longitud);

    return longitud;
}

float round(float number)
{
    return (number<0.0) ? ceil(number - 0.5) : floor(number + 0.5);
}

unsigned int mfcc(unsigned int tamEntrada, unsigned int tamVentana, int solapamiento, float alfa)
{
    unsigned int mul = 0;
    int i, j, k, pos1, pos3;
    float preEnfasis;
    float suma, sumas[13];

    if((menor*(-1))>mayor)
    	mayor = (menor*(-1));

    for(i=0;(i+(signed int)(tamVentana)-1)<(signed int)(tamEntrada) && (mul<624);i=i+(signed int)(solapamiento))
    {
    	for(j=0;j<(signed int)(tamVentana);j++)
        {
            if(j==0 && i==0)
		preEnfasis = (float)(voz[0])/(float)(mayor);
            else
		preEnfasis = ((float)(voz[j+i])/(float)(mayor)) + alfa * ((float)(voz[j+i-1])/(float)(mayor));

            //printf("%f ", preEnfasis);

            sigCmpx[j].real = Float2Fract( ( preEnfasis * (0.54-0.46*cos(2.0*3.14159*(float)(j)/(float)(tamVentana))) ) / 4.0);
            sigCmpx[j].imag = 0x0000;

            //printf("%f ", preEnfasis * (0.54-0.46*cos(2*3.14159*j/tamVentana)));
            //printf("%f ", Fract2Float(sigCmpx[j].real));
        }

        FFTComplexIP (LOG2_BLOCK_LENGTH, &sigCmpx[0], (fractcomplex *) __builtin_psvoffset(&twiddleFactors[0]), (int) __builtin_psvpage(&twiddleFactors[0]));
	BitReverseComplex (LOG2_BLOCK_LENGTH, &sigCmpx[0]);

        for ( j=0; j<(signed int)(FFT_BLOCK_LENGTH); j++ )
	{
            sigCmpx[j].real = Float2Fract( sqrt( (Fract2Float(sigCmpx[j].real)*Fract2Float(sigCmpx[j].real)) + (Fract2Float(sigCmpx[j].imag)*Fract2Float(sigCmpx[j].imag)) ));
            //printf("%f ", Fract2Float(sigCmpx[j].real));
        }

        for(j=0;j<13;j++)
        {
            pos1 = (int)( round( (700.0 * (exp( (j*((1127.0*log(1.0+8000.0/700.0)/14.0)))/1127.0 )-1.0)) / (8000.0/((float)(tamVentana)/2.0))) );
            pos3 = (int)( round( (700.0 * (exp( ((j+2)*((1127.0*log(1.0+8000.0/700.0))/14.0))/1127.0)-1.0)) / (8000.0/((float)(tamVentana)/2.0))) );

            suma = 0.0;

            switch(j)
            {
                case 0:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors1[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 1:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors2[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 2:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors3[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 3:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors4[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 4:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors5[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 5:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors6[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 6:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors7[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 7:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors8[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 8:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors9[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 9:     for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors10[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 10:    for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors11[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 11:    for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors12[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
                case 12:    for(k=pos1; k<=pos3; k++)
                                suma += Fract2Float(hmFactors13[k-pos1]) * (Fract2Float(sigCmpx[k].real) * 1000.0);
                            break;
            }

            //Hasta aqui se parecen las graficas.
            sumas[j] = (suma==0x00000000)?0x00000000:(log(suma));
            //printf("%f ", suma);
        }

        for(j=0;j<13;j++)
        {
            suma = 0x00000000;

            for(k=0;k<13;k++)
            {
                suma += 0.392242 * sumas[k] * cos(3.14159*((float)(j)+1.0)*((float)(k)+0.5)/13.0);
            }

            if(modo==ENTRENAMIENTO)
            //if(modo==RECONOCIMIENTO)
                printf("%f;", suma);
                //printf("%f ", suma);

            //Se guardan las caracteristicas del MFCC en el vector carMFCC de tamaño 624
            carMFCC[j+mul] = suma;

        }

	mul += MUL13;

        //stop = clock();
    }

    return (mul/MUL13);
}

void getPCAValues(float *salida)
{
    unsigned char i;
    unsigned int j;
    float f;

    for(i=0; i<INPUTNEURONS; i++)
    {
	f = 0.0;

	for(j=0; j<624; j++)
	{
            //f += ( (Fract2Float(voz[j])*10.0) - means[j] ) * eigenCov[j][i];
            f += ( carMFCC[j] - means[j] ) * eigenCov[j][i];
	}

	//printf("%f;", f);
	salida[i] = f;
    }
}

void applyMapminmax(float *input)
{
    unsigned char i;

    for(i=0; i<INPUTNEURONS; i++)//Neuronas de entrada
    {
	//y(i) = ps.yrange * ((x(i) - ps.xmin(i)) / rangex(i)) + ps.ymin;
	input[i] = 2.0 * ( (input[i] - ps_xmin[i]) / ps_rangex[i] ) - 1.0 ;
	//printf("%f ", f);
    }

    //printf("\n");
}

signed char forwardPropagation(void)
{
    signed char resultado=-1;
    unsigned char i;
    unsigned int j;
    float s, in[INPUTNEURONS], hiddenL[HIDDENLAYER], mayor=0.0f;

    getPCAValues(in);
    applyMapminmax(in);

    for(i=0; i<HIDDENLAYER; i++)//Hidden Layer
    {
	s = bias1[i];
	for(j=0; j<INPUTNEURONS; j++)//Neuronas de entrada
	{
            s += in[j] * IW[i][j];
	}

	//sigCmpx[i].real = Float2Fract( 2.0/(1.0+exp(-2.0*s))-1.0 );
        hiddenL[i] = 2.0/(1.0+exp(-2.0*s))-1.0;
    }

    for(i=0; i<OUTPUTNEURONS; i++)//Neuronas de salida
    {
	s = bias2[i];

	for(j=0; j<HIDDENLAYER; j++)//Hidden layer
	{
            //s += Fract2Float(sigCmpx[j].real) * LW[i][j];
            s += hiddenL[j] * LW[i][j];
	}

        //ReverseMapMinMax->x(i) = ts.xrange(i)*(y(i)-ts.ymin)*(1/ts.yrange) + ts.xmin(i);
	s = 1 * ( (2.0/(1.0+exp(-2.0*s))-1.0) + 1.0 ) * 0.5;
	//sigCmpx[i].imag = Float2Fract(s);
	//Fin  ReverseMapMinMax

        //printf("%f\n", s);//Imprime valor de cada neurona

	//if((1.00000-s)<0.4 && restaAbs(s, valorMayorRNA)>0.4)

        //salidaRNA[i] = s;

        if( (s-mayor)>0.4 )
            resultado = i;

        if(s>mayor)
            mayor = s;
    }

    
    //stop = clock();
    /*s = 0.3f;
    for(i=0; i<OUTPUTNEURONS; i++)
    {
        printf("%f\n", salidaRNA[i]);

        if(restaAbs(salidaRNA[i],s)<0.05)
            return -1;
        else if( (1.00000-salidaRNA[i])<0.6 )
            resultado = i;

        if(salidaRNA[i]>s)
            s = salidaRNA[i];
    }*/

    return resultado;
}

float restaAbs(float a, float b)
{
   return (a>b)?(a-b):(b-a);
}