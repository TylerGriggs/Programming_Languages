#include "Tokenizer.h"
#include "stdio.h"
#include "string.h"
#include "regex.h"

_Bool tokenize(struct lexics *aLex, int *numLex, FILE *inf){
    char textArray[MY_CHAR_MAX];
    int word_count = 0;

    while (fgets(textArray, MY_CHAR_MAX, inf) != NULL){

        int l_i = 0; // Line Index
        char c = textArray[l_i];
        while (c != '\0' && c !='\n'){

            int token = 0; //token_id Integer, list found in Givens.h
            int w_i = 0; //Word Index
            char current_word[MY_CHAR_MAX];

            if (isspace(c)){
                l_i++;
                w_i++;
                continue;
            }
            else if (isalpha(c)){
                current_word[w_i] = c;
                l_i++;
                w_i++;
                while (isalpha(textArray[l_i]) || isdigit(textArray[l_i])){
                    current_word[w_i] = textArray[l_i];
                    l_i++;
                    w_i++;
                }
                //Lexeme now loaded into current_word[]
                if (strcmp(current_word, "while") == 0){token = WHILE_KEYWORD; }
                else if (strcmp(current_word, "return") == 0){token = RETURN_KEYWORD;} 
                else if (strcmp(current_word, "int") == 0){token = VARTYPE;}
                else if (strcmp(current_word, "void") == 0){token = VARTYPE;}
                else {token = IDENTIFIER;}
            }
            else if (isdigit(c)){
                current_word[w_i] = c;
                l_i++;
                w_i++;
                while (isdigit(textArray[l_i])){
                    current_word[w_i] = textArray[l_i];
                    l_i++;
                    w_i++;
                }
                //Lexeme now loaded into current_word[]

            }
            else {
                //IF SPECIAL CHARACTER
                current_word[w_i] = c;
                //Lexeme now loaded into current_word[] 1 character
                if (c == ";"){token = EOL; break;}
                else if (c == ","){token = COMMA; break;}
                else if (c == "+"){token = BINOP; break;}
                else if (c == "*"){token = BINOP; break;}
                else if (c == "%"){token = BINOP; break;}
                else if (c == "("){token = LEFT_PARENTHESIS; break;}
                else if (c == ")"){token = RIGHT_PARENTHESIS; break;}
                else if (c == "{"){token = LEFT_BRACKET; break;}
                else if (c == "}"){token = RIGHT_BRACKET; break;}

                else if (c == "="){
                    if (textArray[l_i + 1] == "="){
                        l_i++;
                        w_i++;
                        current_word[w_i] = "=";
                        token = BINOP; break;
                        }
                    token = EQUAL; break;
                    }

                else if (c == "!"){
                    if (textArray[l_i + 1] == "="){
                        l_i++;
                        w_i++;
                        current_word[w_i] = "=";
                        token = BINOP; break;
                        }
                    }
                //Lexeme now loaded into current_word[] 2 characters

            }
            c = textArray[l_i];
            struct lexics *lexeme_ready = (struct lexics *) malloc(sizeof(struct lexics));
            strcopy(lexeme_ready->lexeme, current_word);
            lexeme_ready->token = token;
            aLex[word_count] = lexeme_ready;
            word_count++;
            memset(current_word, "\0", sizeof(current_word));
        }
    }

    *numLex = word_count;
    return TRUE;
}