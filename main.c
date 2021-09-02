#include <stdio.h>
#include <stdlib.h>
#define Nb 4

unsigned int CipK128[4][8]=
    {
    0x2b,0x28,0xab,0x09,
    0x7e,0xae,0xf7,0xcf,
    0x15,0xd2,0x15,0x4f,
    0x16,0xa6,0x88,0x3c
    };
/*unsigned int error[4][Nb]=
    {
    -1,-1,-1,-1,
    -1,-1
    }*/
unsigned int CipK256[4][8]=
    {
    0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,
    0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,
    0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,
    0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4
    };
unsigned int test[4][Nb]=
    {
    0x19,0xa0,0x9a,0xe9,
    0x3d,0xf4,0xc6,0xf8,
    0xe3,0xe2,0x8d,0x48,
    0xbe,0x2b,0x2a,0x08
    };
unsigned int test2[4][Nb]=
    {
        0x32,0x88,0x31,0xe0,
        0x43,0x5a,0x31,0x37,
        0xf6,0x30,0x98,0x07,
        0xa8,0x8d,0xa2,0x34
    };
unsigned int test3[4]={0x09,0xcf,0x4f,0x3c};

unsigned int Sbox[16][16] =
    {
      0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
      0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
      0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
      0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
      0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
      0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
      0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
      0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
      0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
      0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
      0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
      0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
      0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
      0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
      0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
      0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
    };
unsigned int InvSbox[16][16]=
    {
        0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb,
        0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb,
        0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e,
        0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25,
        0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92,
        0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84,
        0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06,
        0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b,
        0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73,
        0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e,
        0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b,
        0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4,
        0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f,
        0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef,
        0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61,
        0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d
    };

void SubBytes(unsigned int S[4][Nb])
    {
        unsigned int i=0,j=0,v=0xf,w=0xf0;
        for(i=0;i<4;i++)
            {
                for(j=0;j<Nb;j++)
                    {
                        S[i][j]=Sbox[(S[i][j]&w)>>4][S[i][j]&v];
                    }
            }

    }

void ShiftRows(unsigned int S[4][Nb])
    {
        unsigned int S1[4][Nb];
        int i=0,j=0;
        for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                    {
                        S1[i][j]=S[i][(i+j)%Nb];
                    }
                for(j=0;j<4;j++)
                    {
                        S[i][j]=S1[i][j];
                    }
            }
    }
unsigned int xtime(unsigned a)
    {
        unsigned int b=0;
        b=a*2;
        if(b&0x100)
            {
                b^=0x11b;
            }
        return b;
    }
unsigned int multff(unsigned int a,unsigned int b)
{
    unsigned int c=b,d=a,s=0x02,e=0x0,d1=0x0;
     while(e!=b)
        {
            s=0x02,d=a;
            while(c>=s)
                {
                    d=xtime(d);
                    s=s*2;
                }
            c^=(s>>1);
            e^=(s>>1);
            d1^=d;
        }
    return d1;
}
void MixColumns(unsigned int S[4][Nb])
    {
        unsigned int S1[4][Nb],j=0;
        for(j=0;j<Nb;j++)
            {
                S1[0][j]=multff(S[0][j],0x02)^multff(S[1][j],0x3)^S[2][j]^S[3][j];
                S1[1][j]=S[0][j]^multff(S[1][j],0x02)^multff(S[2][j],0x03)^S[3][j];
                S1[2][j]=S[0][j]^S[1][j]^multff(S[2][j],0x02)^multff(S[3][j],0x03);
                S1[3][j]=multff(S[0][j],0x03)^S[1][j]^S[2][j]^multff(S[3][j],0x02);
                S[0][j]=S1[0][j];
                S[1][j]=S1[1][j];
                S[2][j]=S1[2][j];
                S[3][j]=S1[3][j];

        }
    }
void AddRoundKey(unsigned int S[4][Nb],unsigned int W[4][Nb])
    {
        int i=0,j=0;
        for(j=0;j<Nb;j++)
            {
                for(i=0;i<4;i++)
                    {
                        S[i][j]=S[i][j]^W[i][j];
                    }
            }
    }
void SubWord(unsigned int *w)
    {
        unsigned int k=0,v=0xf,y=0xf0;
        for(k=0;k<4;k++)
            {
                *(w+k)=Sbox[(*(w+k)&y)>>4][*(w+k)&v];
            }
    }
void RotWord(unsigned int *w)
    {
        unsigned int k=0,v=*w;
        for(k=0;k<3;k++)
            {
                *(w+k)=*(w+k+1);
            }
        *(w+3)=v;
    }
unsigned int *Rcon(unsigned int i)
    {
        unsigned int a=0x0,j=0,*p;
        p=calloc(4,sizeof(unsigned int));
        if(i==1) a=0x01;
        else if(i>1)
            {
                a=0x02;
            }
        for(j=2;j<i;j++)
            {
                a=xtime(a);
            }
        p[0]=a;
        p[1]=0x0;
        p[2]=0x0;
        p[3]=0x0;
        return p;
    }
unsigned int KeyExpansion(unsigned int *K,unsigned int Nk)
    {
        unsigned int Nr=0,**W,*w,i=0,j=0,*temp;
        if(Nk==4) Nr=10;
        else if(Nk==6) Nr=12;
        else if(Nk==8) Nr=14;

        w = (unsigned int*)calloc(4*Nb*(Nr+1),sizeof(unsigned int));
        W = (unsigned int **) calloc(Nb*(Nr+1),sizeof(unsigned int *));
        for(i=0;i<Nb*(Nr+1);i++) W[i] = &w[i*4];

        for(i=0;i<Nk;i++)
            {
                for(j=0;j<4;j++)
                    {
                        W[i][j]=*(K+i+j*Nk);


                    }

            }
        for(i=Nk;i<((Nr+1)*Nb);i++)
            {
               temp=calloc(4, sizeof(unsigned int));
               for(j=0;j<4;j++) temp[j]=W[i-1][j];

                if((i%Nk)==0)
                    {
                        RotWord(temp);
                        SubWord(temp);
                        for(j=0;j<4;j++) *(temp+j)=*(temp+j)^Rcon(i/Nk)[j];
                    }
                else if((Nk>6)&&((i%Nk)==4))
                            {
                              SubWord(temp);
                            }
               for(j=0;j<4;j++) W[i][j]=W[i-Nk][j]^temp[j];
               free(temp);
            }
        return W;
    }
void Roundkey(unsigned int **K,unsigned int Rk[4][Nb], unsigned int k)
    {
        unsigned int i=0,j=0;
        for(i=0;i<4;i++)
            {
                for(j=0;j<Nb;j++)
                    {
                        Rk[i][j]=K[j+k*Nb][i];
                    }
            }

    }
void Cipher(unsigned int **Input, unsigned int **KeyE, unsigned int Nk)
    {
        unsigned int Rk[4][Nb],i=0,Nr=0;
        switch(Nk)
        {
            case 4:
                Nr=10;
                break;
            case 6:
                Nr=12;
                break;
            case 8:
                Nr=14;
                break;
        }
        Roundkey(KeyE,Rk,i);
        AddRoundKey(Input,Rk);
        for(i=1;i<Nr;i++)
            {
                SubBytes(Input);
                ShiftRows(Input);
                MixColumns(Input);
                Roundkey(KeyE,Rk,i);
                AddRoundKey(Input,Rk);
            }

        SubBytes(Input);
        ShiftRows(Input);
        Roundkey(KeyE,Rk,Nr);
        AddRoundKey(Input,Rk);

    }
void InvShiftRows(unsigned int S[4][Nb])
    {
        unsigned int S1[4][Nb];
        int i=0,j=0;
        for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                    {
                        S1[i][j]=S[i][(Nb-i+j)%Nb];
                    }
                for(j=0;j<4;j++)
                    {
                        S[i][j]=S1[i][j];
                    }
            }
    }

void InvSubBytes(unsigned int S[4][Nb])
    {
        unsigned int i=0,j=0,v=0xf,w=0xf0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<Nb;j++)
            {
                S[i][j]=InvSbox[(S[i][j]&w)>>4][S[i][j]&v];
            }
        }

    }

void InvMixColumns(unsigned int S[4][Nb])
    {
        unsigned int S1[4][Nb],j=0;
        for(j=0;j<Nb;j++)
            {
                S1[0][j]=multff(S[0][j],0x0e)^multff(S[1][j],0x0b)^multff(S[2][j],0x0d)^multff(S[3][j],0x09);
                S1[1][j]=multff(S[0][j],0x09)^multff(S[1][j],0x0e)^multff(S[2][j],0x0b)^multff(S[3][j],0x0d);
                S1[2][j]=multff(S[0][j],0x0d)^multff(S[1][j],0x09)^multff(S[2][j],0x0e)^multff(S[3][j],0x0b);
                S1[3][j]=multff(S[0][j],0x0b)^multff(S[1][j],0x0d)^multff(S[2][j],0x09)^multff(S[3][j],0x0e);
                S[0][j]=S1[0][j];
                S[1][j]=S1[1][j];
                S[2][j]=S1[2][j];
                S[3][j]=S1[3][j];

        }
    }
void EqInvCipher(unsigned int **Input, unsigned int **KeyE, unsigned int Nk)
    {
        unsigned int Rk[4][Nb],i=0,Nr=0;
        switch(Nk)
        {
            case 4:
                Nr=10;
                break;
            case 6:
                Nr=12;
                break;
            case 8:
                Nr=14;
                break;
        }

        Roundkey(KeyE,Rk,Nr);
        AddRoundKey(Input,Rk);
        InvSubBytes(Input);
        InvShiftRows(Input);
        for(i=1;i<Nr;i++)
            {
                Roundkey(KeyE,Rk,Nr-i);
                AddRoundKey(Input,Rk);
                InvMixColumns(Input);
                InvSubBytes(Input);
                InvShiftRows(Input);
            }
        Roundkey(KeyE,Rk,0);
        AddRoundKey(Input,Rk);

    }
void DoCipher(unsigned int **K,unsigned int Nk)
    {
        unsigned int i=0,j=0,c=0,input[4][Nb];
        FILE *Al=NULL;
        FILE *Ci=NULL;
        Al=fopen("alice.txt","r");
        Ci=fopen("Cipher Alice.txt","w");
        if (Al==NULL)
            {
                printf ("Wrong file !\n");
                return(1);
            }
        while(c!=EOF)
            {

                for(i=0;i<4;i++)
                    {
                        for(j=0;j<Nb;j++)
                            {
                                c=fgetc(Al);
                                if(c==EOF)
                                    {
                                        input[i][j]=0;
                                    }
                                else
                                    {
                                        input[i][j]=c;
                                    }

                            }
                    }
                Cipher(input,K,Nk);
                for(i=0;i<4;i++)
                    {
                        for(j=0;j<Nb;j++)
                            {
                                fprintf(Ci,"%c",input[i][j]);
                            }
                    }

            }
    }
void DoInvCipher(unsigned int **K,unsigned int Nk)
    {
        unsigned int i=0,j=0,c=0,k=0,input[4][Nb];
        FILE *InvAl=NULL;
        FILE *Ci=NULL;
        InvAl=fopen("Invcipher  alice.txt","w");
        Ci=fopen("Cipher Alice.txt","r");
        if (Ci==NULL)
            {
                printf ("Wrong file !\n");
                return(1);
            }

        while(c!=EOF)
            {
                k++;
                for(i=0;i<4;i++)
                    {
                        for(j=0;j<Nb;j++)
                            {
                                c=fgetc(Ci);
                                input[i][j]=c;
                                 printf("\n %0x", c);
                                //printf("%c",c);
                            }
                    }
                EqInvCipher(input,K,Nk);
                for(i=0;i<4;i++)
                    {
                        for(j=0;j<Nb;j++)
                            {
                                fprintf(InvAl,"%c",input[i][j]);
                            }
                    }

            }
            printf("\n %d",k);
            printf("\n %d", c);
    }

int main()
{
    int i=0,j=0;
    //AddRoundKey(test2,CipK128);
    SubBytes(test);
    ShiftRows(test);
    InvShiftRows(test);
   /* MixColumns(test2);
    SubWord(test3);
    RotWord(test3);*/
    unsigned int **K=KeyExpansion(CipK256,4);
    unsigned int Rk[4][Nb];
    Cipher(test2,K,4);
    EqInvCipher(test2,K,4);
    for(i=0;i<4;i++)
    {
        for(j=0;j<Nb;j++)
       {
           printf("%0x",test2[i][j]);
       }
       printf("\n");
    }
    DoCipher(K,4);
    DoInvCipher(K,4);

}
