.section .text
.globl _start
_start:                         # ponto de entrada do programa
    addi x1, x0, 2              # x1 <- 2 (valor a ser somado repetidamente)
    addi x2, x0, 5              # x2 <- 5 (contador de repeticoes)
    addi x3, x0, 0              # x3 <- 0 (acumulador do resultado)

repeat_addition:                # inicio do loop de soma
    add x3, x3, x1              # x3 <- x3 + x1 (soma acumulada)
    addi x2, x2, -1             # x2 <- x2 - 1 (decrementa o contador)
    bne x2, x0, repeat_addition # se x2 != 0, volta ao inicio do loop

j .                             # loop infinito: salta para o endereco atual
                                # (fim do programa)
