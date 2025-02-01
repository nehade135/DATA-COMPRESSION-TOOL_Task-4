#include <stdio.h>
#include <string.h>
void compressRLE(const char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        
        int count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];
        output[j++] = count + '0'; 
        i++;
    }
    output[j] = '\0'; 
}
void decompressRLE(const char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
       
        char ch = input[i++];
        int count = input[i++] - '0';
        int k;
        for (k=0;k<count;k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0'; 
}
int main() {
	
    char input[1000], compressed[1000], decompressed[1000];
    int choice;
    printf("Run-Length Encoding (RLE) Tool\n");
    printf("Enter 1 to Compress or 2 to Decompress: ");
    scanf("%d", &choice);
    getchar(); 
    if (choice == 1) {
    	
        printf("Enter the text to compress: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 
        compressRLE(input, compressed);
        printf("Compressed Text: %s\n", compressed);
    } 
	else if (choice == 2) {
        printf("Enter the text to decompress: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 
        decompressRLE(input, decompressed);
        printf("Decompressed Text: %s\n", decompressed);
    }
	 else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}
