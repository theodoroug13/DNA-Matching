#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getDna(char **a, FILE *file){  // function που διαβάζει το dna file
    int c;
    int i=0;
    c= fgetc(file);
    while (c!= EOF){
        if(c=='A' || c== 'G' || c=='C' || c=='T'){        // Βάσεις dna
        *a=realloc(*a, (i+1)*sizeof(char));      // κάθε χαρακτήρα π διαβαζουμε αναθέτουμε μνήμη για άλλον ένα χαρακτήρα
        if(!*a){
            return 1;
        }
        (*a)[i]=c;                                   
        i++ ;
        }
        
        c=fgetc(file);
    }
    (*a)[i]='\0';                                        // null byte στο τέλος του string
    
return 0;
}


int main(int argc, char *argv[]) {
    if(argc != 3) {
        return 1;
    }

    FILE* file1 = fopen(argv[1], "r");
    FILE* file2 = fopen(argv[2], "r");
    
    char *s1 = NULL;
    char *s2 = NULL;
    int val = getDna(&s1, file1);
    if(val == 1) {
        return 1;  // malloc failed
    }
    
    val = getDna(&s2, file2);
    if(val == 1) {
        return 1;  // malloc failed
    }

    int length1 = strlen(s1);
    int length2 = strlen(s2);

    int maxcount = 0;
    int start = 0;

    for (int i = 0; i < length1; i++) {          //βρίσκουμε το μήκος της μεγαλύτερης κοινής συμβολοσειράς
        for (int j = 0; j < length2; j++) {
            int count = 0;
            int a = i;
            int b = j;

            while (s1[a] == s2[b] && a < length1 && b < length2) {
                count++;
                a++;
                b++;
            }

            if (count > maxcount) {
                maxcount = count;
                start = i;
            }
        }
    }

    char *lcs = malloc((maxcount + 1) * sizeof(char));
    int index = 0;
    for (int c = start; c < start + maxcount; c++) {     //φτιάχνουμε την συμβολοσειρά
        lcs[index++] = s1[c];
    }
    lcs[maxcount] = '\0';                                       //προσθέτουμε τον χαρακτήρα τέλους του string

    printf("%s\n", lcs);

    free(lcs);
    free(s1);
    free(s2);
    fclose(file1);
    fclose(file2);

    return 0;
}