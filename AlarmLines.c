// Do not initialize inputs!

#define EMPTY_SPACE 538976288
#define HEX_INTERPRETER 16777216
#define SYMBOL_SHIFT 256
#define BREAK_LINE_SYMBOL 127
#define ARRAY_STRING_SIZE 16
#define STRING_SIZE 4

long DataOut[ARRAY_STRING_SIZE][STRING_SIZE];

void Init(void)
{
  short i;
  for(i=0;i<ARRAY_STRING_SIZE;i++)
    {
      (&v->String0)[i] = (long)&DataOut[i];
    }

}


void Exec(void)
{
  short z,j=0,i,numExit=0, DataCont=0;
  long bintrans=*v->MaskBin, hexator=HEX_INTERPRETER;
  long *DataInter = (long *)*v->Alphabet;
  for (i=0;i<ARRAY_STRING_SIZE;i++)
    {
    for (j=0;j<STRING_SIZE;j++)
      {
       DataOut[i][j]=EMPTY_SPACE;
      }
     }
  if (*v->Alphabet)
   {
    for(i=0;i<*v->AlphabetCount;i++)
     {
      if (bintrans % 2 == 1 && i-j<15)
        {
        if(DataInter[i]!=BREAK_LINE_SYMBOL)
           {
             DataOut[numExit][DataCont]+=(DataInter[i]*hexator)+(-32*hexator);
           }
        if ((hexator!=1) && (DataInter[i]!=BREAK_LINE_SYMBOL))
           {
             hexator/=SYMBOL_SHIFT;
           }
        else
           {
             if ((DataCont<3) && (DataInter[i]!=BREAK_LINE_SYMBOL))
              {
               DataCont++;
              }
             else
              {
               if(DataInter[i]!=BREAK_LINE_SYMBOL)
               {
                 for(z=i;z>j;z--)
                  {
                   DataOut[numExit][DataCont]+=(-DataInter[z]*hexator)+(32*hexator);
                   if(hexator==HEX_INTERPRETER)
                    {
                     hexator=1;DataCont--;
                    }
                    else
                    {
                     hexator*=SYMBOL_SHIFT;
                    }
                   }
               i=j;
               }
               DataCont=0;
               numExit++;
               }
             hexator = HEX_INTERPRETER;
           }
         }
      if ((DataInter[i]== *v->BreakingPoint && j!=i) || (DataInter[i]==BREAK_LINE_SYMBOL))
        {
         if(DataInter[i]!=BREAK_LINE_SYMBOL)
          {
           if (bintrans % 2 == 1)
           {
             bintrans=bintrans-1;
           }
           bintrans=bintrans/2;
          }
         j=i;
        }
     }
   }
   v->NumString =  numExit;
  }
