#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num, char* temp) //a function that parsing according to seperator
{
    const char* tok;
    for (tok = strtok(line, temp);
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
	 
    FILE* stream = fopen(argv[1], "r");        //reading file
    FILE *fp;
    fp = fopen(argv[2],"w");                   //writing file
    char* temp = ",";                             
    if(strcmp(argv[4], "1") == 0 )             //operations for choosing the seperator
    {
    temp = ",";
    }
    else if(strcmp(argv[4] , "2") == 0)
    {
        temp = "\t";
    }
    else if(strcmp(argv[4] , "3") == 0)
    {
        temp = ";";
    }
    
    char line[1024];
    char* filename = strtok(argv[1],".");       //saving name of csv file
    printf("<");
    printf(filename);
    printf(">");
     fprintf(fp, "<");    	
     fprintf(fp, filename);    	
      fprintf(fp, ">");    	
    printf("\n");
     fprintf(fp, "\n");    	
    int count=1;                          //counter for every line in csv file
    while (fgets(line, 1024, stream))
    {
    	printf("<row id = ");
        printf("%d",count);
        printf(">");
        printf("\n");
        fprintf(fp, "<row id = ");    	
        fprintf(fp,"%d",count);    	
        fprintf(fp,">");    	  
        fprintf(fp,"\n");
    	char* tmp = strdup(line);
    	printf("<first_name>");
        printf(getfield(tmp, 1, temp));
        printf("%s\n",  "</first_name>");
         fprintf(fp, "<first_name>");
         fprintf(fp, getfield(tmp, 1, temp));
         fprintf(fp, "%s\n",  "</first_name>");
       tmp = strdup(line);
          if(getfield(tmp, 2, temp) == NULL)
          printf("%s\n",  "<last_name/>");
          else{
         printf("<last_name>");
         tmp = strdup(line);
         printf(getfield(tmp, 2, temp));
         printf("%s\n",  "</last_name>");
         fprintf(fp, "<last_name>");
         tmp = strdup(line);
         fprintf(fp, getfield(tmp, 2, temp));
         fprintf(fp, "%s\n",  "</last_name>");
     		}
         tmp = strdup(line);
          if(getfield(tmp, 3, temp) == NULL)
          printf("%s\n",  "<email/>");
          else{
         printf("<email>");
         tmp = strdup(line);
         printf(getfield(tmp, 3, temp));
         printf("%s\n",  "</email>");
         fprintf(fp, "<email>");
         tmp = strdup(line);
         fprintf(fp, getfield(tmp, 3, temp));
         fprintf(fp, "%s\n",  "</email>");
     		}
          tmp = strdup(line);
          if(getfield(tmp, 4, temp) == NULL)
          printf("%s\n",  "<phone_number/>");
          else{
         printf("<phone_number>");
         tmp = strdup(line);
         printf(getfield(tmp, 4, temp));
         printf("%s\n",  "</phone_number>");
          fprintf(fp, "<phone_number>");
          tmp = strdup(line);
         fprintf(fp, getfield(tmp, 4, temp));
         fprintf(fp, "%s\n",  "</phone_number>");
     		}
         tmp = strdup(line);
          if(getfield(tmp, 5, temp) == NULL ){
          printf("%s\n",  "<address/>");
          }
          else{
         printf("<address>");
         tmp = strdup(line);
         printf(getfield(tmp, 5, temp));
         printf("%s\n",  "</address>");
           fprintf(fp, "<address>");
           tmp = strdup(line);
         fprintf(fp, getfield(tmp, 5, temp));
         fprintf(fp, "%s\n",  "</address>");
     		}
     
        free(tmp);
        printf("</row>");
        fprintf(fp, "</row>");
        printf("\n");
        fprintf(fp, "\n");
          printf("\n");
          fprintf(fp, "\n");
        count++;
    }
      printf("<");
    printf(filename);
    printf(">");
     fprintf(fp, "<");    	
     fprintf(fp, filename);    	
      fprintf(fp, ">"); 
    fclose(fp);
}