#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *read_file(char *filepath) {
    // open the file
    FILE* ptr;
    char ch;
    ptr = fopen(filepath, "r");
 
    if (NULL == ptr) {
        return 0;
    }
    // read the file and save to a variable called file_contents
    char *file_contents = malloc(1000);
    int i = 0;
    while ((ch = fgetc(ptr)) != EOF) {
        file_contents[i] = ch;
        i++;
    }
    fclose(ptr);
    return file_contents;
}

char *shift_characters(char *file_contents) {
    // for each character in the file_contents string, convert the character to an int
    for(int i = 0; i < strlen(file_contents); i++) {
        // ensure the character is a letter
        if(isalpha(file_contents[i])) {
            // convert the character to an upper case
            file_contents[i] = toupper(file_contents[i]);
            // convert the character to an int
            int char_int = (int)file_contents[i];
            // shift the character by 5
            char_int = char_int - 65;
            char_int = char_int + 5;
            // mod character by 26
            char_int = char_int % 26;
            char_int = char_int + 65;
            // convert the character back to a char
            file_contents[i] = (char)char_int;
        }
    }
    return file_contents;

}

void rename_file(char *filepath) {
    // rename the file
    char *new_filepath = malloc(1000);
    char *flag = "flag{Strings_are_fun}";
    strcpy(new_filepath, filepath);
    strcat(new_filepath, ".encrypted");
    rename(filepath, new_filepath);
}

void write_file(char *filepath, char *file_contents) {
    // open the file for writing
    FILE *file = fopen(filepath, "w");
    // write the file contents to the file
    fprintf(file, "%s", file_contents);
    // close the file
    fclose(file);
}

void encrypt_file(char *filepath) {
    // call a read file function that returns the contents of the file as a string
    char *file_contents = read_file(filepath);
    // call a function that encrypts the file contents
    char *encrypted_file_contents = shift_characters(file_contents); 
    // call a function that writes the encrypted file contents to the file
    write_file(filepath, encrypted_file_contents);

}
int main( int argc, char *argv[] )  {

   if( argc == 2 ) {
      encrypt_file(argv[1]);
   }
   else if( argc > 2 ) {
      return 0;
   }
   else {
      return 0;
   }
}










