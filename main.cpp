#include <iostream>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

/* subleq a, b, c
 * pgrm_memory[b] = pgrm_memory[b] - pgrm_memory[a]
 * if(pgrm_memory[b] <= 0} pgrm_counter = c;
 */

#define BYTES 1024

struct instruction{
    public: instruction(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int a,b,c;
};

void subleq(instruction *i);
void displaySyntaxMessage();

int parseSubleqFile(const char *string);

uint8_t pgrm_counter;
int *pgrm_memory;

int main(int argc, const char* argv[]) {

    if(argc < (1 + 3)){
        displaySyntaxMessage();
        return -1;
    }

    uint8_t instructionCount = argc - 1;

    pgrm_memory = new int[instructionCount];
    for(uint8_t i = 0; i < instructionCount; i++){
        pgrm_memory[i] = strtol(argv[i + 1], NULL, 10);
    }

    while(pgrm_counter <= instructionCount) {
        instruction *i = new instruction(pgrm_counter, pgrm_counter + 1, pgrm_counter + 2);
        subleq(i);
    }

   return 0;
}

void displaySyntaxMessage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "tsubleq [filepath]" << std::endl;
}

/*Interpret a subleq instruction*/
void subleq(instruction *subleqInstruction){
    /*output char character*/

    if(pgrm_memory[subleqInstruction->b] == -1){
        std::cout << (char) pgrm_memory[pgrm_memory[subleqInstruction -> a]] << std::flush; //this seems wrong
    }

    /*Subtract a from b*/
    pgrm_memory[subleqInstruction->b] -= pgrm_memory[subleqInstruction->a];

    /*if less than or equal to 0*/
    if(pgrm_memory[subleqInstruction->b] <= 0){
        //branch to b
        pgrm_counter = pgrm_memory[subleqInstruction->c];
    }else{

        //Jump ahead to the next instruction
        pgrm_counter += 3;
    }

}