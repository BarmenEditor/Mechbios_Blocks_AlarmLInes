// Do not initialize inputs!

#define EMPTY_SPACE 538976288
#define HEX_INTERPRETER 16777216
#define SYMBOL_SHIFT 256
#define SYMBOL_MASK 255
#define BREAK_LINE_SYMBOL 127
#define EMPTY_SYMBOL 32
#define ARRAY_STRING_SIZE 64
#define STRING_SIZE 4

unsigned long dataout[ARRAY_STRING_SIZE][STRING_SIZE];

void Init(void)
{
  unsigned short i;
  for(i=0;i<ARRAY_STRING_SIZE;i++)
    {
      (&v->String0)[i] = (long)&dataout[i];
    }
}


void Exec(void)
{
  unsigned short i;
  unsigned char z;
  unsigned short j=0;
  unsigned char resshift=0;
  unsigned char numberstringout=0;
  unsigned char datastringcontainer=0;
  unsigned long bintransformator=*v->MaskBin;
  unsigned long hextransformator=HEX_INTERPRETER;
  long *dataenter = (long *)*v->Alphabet;
  for (i=0;i<ARRAY_STRING_SIZE;i++)
    {
    for (z=0;z<STRING_SIZE;z++)
      {
       dataout[i][z]=EMPTY_SPACE;
      }
     }
  if (*v->Alphabet)
   {
    for(i=0;i<(4*(*v->AlphabetCount));i++)
     {
      if (bintransformator % 2 == 1 && i-j<((4*STRING_SIZE)-1) && (numberstringout < ARRAY_STRING_SIZE))
        {
        if(dataenter[i]!=BREAK_LINE_SYMBOL)
           {
             dataout[numberstringout][datastringcontainer]+=(((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)*hextransformator)+(-EMPTY_SYMBOL*hextransformator);
           }
        if ((hextransformator!=1) && ((dataenter[i/4]>>(8*(i%4))&SYMBOL_MASK)!=BREAK_LINE_SYMBOL))
           {
             hextransformator/=SYMBOL_SHIFT;
           }
        else
           {
             if ((datastringcontainer<(STRING_SIZE-1)) && (((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)!=BREAK_LINE_SYMBOL))
              {
               datastringcontainer++;
              }
             else
              {
               if(((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)!=BREAK_LINE_SYMBOL)
               {
                 for(z=i;z>j;z--)
                  {
                   dataout[numberstringout][datastringcontainer]+=(-((dataenter[z/4]>>(8*(z%4)))&SYMBOL_MASK)*hextransformator)+(EMPTY_SYMBOL*hextransformator);
                   if(hextransformator==HEX_INTERPRETER)
                    {
                     hextransformator=1;
                     datastringcontainer--;
                    }
                    else
                    {
                     hextransformator*=SYMBOL_SHIFT;
                    }
                   }
               i=j;
               }
               datastringcontainer=0;
               numberstringout++;
               }
             hextransformator = HEX_INTERPRETER;
           }
         }
      if ((((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)== *v->BreakingPoint && j!=i) || (((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)==BREAK_LINE_SYMBOL))
        {
         if(((dataenter[i/4]>>(8*(i%4)))&SYMBOL_MASK)!=BREAK_LINE_SYMBOL)
          {
           bintransformator>>=1;
             if(resshift>29 && resshift<60)
                  {
                    bintransformator+=(((*v->MaskBinRes>>(resshift-30))%2));
                  }
                resshift++;

          }
         j=i;
        }
     }
   }
   v->NumString =  numberstringout;
  }
