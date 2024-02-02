// Do not initialize inputs!

#define EMPTY_SPACE 538976288
#define HEX_INTERPRETER 16777216
#define SYMBOL_SHIFT 256
#define BREAK_LINE_SYMBOL 127
#define EMPTY_SYMBOL 32
#define ARRAY_STRING_SIZE 16
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
  unsigned short i=0; // Присутствует возможность зайти за диапазон char
  unsigned char z=0;
  unsigned short j=0; // Присутствует возможность зайти за диапазон char
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
    for(i=0;i<*v->AlphabetCount;i++)
     {
      if (bintransformator % 2 == 1 && i-j<((4*STRING_SIZE)-1) && (numberstringout < ARRAY_STRING_SIZE))
        {
        if(dataenter[i]!=BREAK_LINE_SYMBOL)
           {
             dataout[numberstringout][datastringcontainer]+=(dataenter[i]*hextransformator)+(-EMPTY_SYMBOL*hextransformator);
           }
        if ((hextransformator!=1) && (dataenter[i]!=BREAK_LINE_SYMBOL))
           {
             hextransformator/=SYMBOL_SHIFT;
           }
        else
           {
             if ((datastringcontainer<(STRING_SIZE-1)) && (dataenter[i]!=BREAK_LINE_SYMBOL))
              {
               datastringcontainer++;
              }
             else
              {
               if(dataenter[i]!=BREAK_LINE_SYMBOL)
               {
                 for(z=i;z>j;z--)
                  {
                   dataout[numberstringout][datastringcontainer]+=(-dataenter[z]*hextransformator)+(EMPTY_SYMBOL*hextransformator);
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
      if ((dataenter[i]== *v->BreakingPoint && j!=i) || (dataenter[i]==BREAK_LINE_SYMBOL))
        {
         if(dataenter[i]!=BREAK_LINE_SYMBOL)
          {
           if (bintransformator % 2 == 1)
           {
             bintransformator--;
           }
           bintransformator/=2;
          }
         j=i;
        }
     }
   }
   v->NumString =  numberstringout;
  }
