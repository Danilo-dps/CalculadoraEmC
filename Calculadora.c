#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função para converter de decimal para binário
int decimalParaBinario(int n) {
    int binario = 0, resto, temp = 1;

    while (n != 0) {
        resto = n % 2;
        n /= 2;
        binario += resto * temp;
        temp *= 10;
    }
    return binario;
}

// Função para converter de decimal para hexadecimal
void decimalParaHexadecimal(int num1) {
    char hexaDeciNum[100];
    int i = 0;
    int j;
    while(num1!=0) {
        int temp  = 0;
        temp = num1 % 16;
        if(temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        } else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        num1 = num1/16;
    }
    for(j=i-1; j>=0; j--)
        printf("%c", hexaDeciNum[j]);
}

int main() {
		setlocale (LC_ALL, "Portuguese");
    char operador;
    int num1, num2, resultado, resto;
    
    printf("Digite a operação desejada (+, -, *, /, %%, b, h): ");
    scanf(" %c", &operador);
    
    if(operador == 'b' || operador == 'h'){
    	printf("Digite um número:");
    	scanf("%d", &num1);
	}
	else{
		printf("Digite dois números: ");
        scanf("%d %d", &num1, &num2);
	}
    
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %d\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %d\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %d\n", resultado);
            break;
        case '/':
            if(num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %d\n", resultado);
            } else {
                printf("Erro: Divisão por zero.\n");
            }
            break;
        case '%':
            if(num2 != 0) {
                resto = num1 % num2;
                printf("Resto da divisão: %d\n", resto);
            } else {
                printf("Erro: Divisão por zero.\n");
            }
            break;
        case 'b':
            printf("Resultado em binário: %d\n", decimalParaBinario(num1));
            break;
        case 'h':
            printf("Resultado em hexadecimal: ");
            decimalParaHexadecimal(num1);
            printf("\n");
            break;
        default:
            printf("Operador inválido.\n");
    }
    
    return 0;
}

