#Bryan Kline
#CS219 HW #3
#02/27/2016
#2.

.data

intArray:   .word 0x5, 0x9, 0x4, 0xff, 0xfe, 0xfa, 0x7, 0x2, 0x8, 0xfd
size:       .word 10
result:     .space 4

.text

main:                   #main

    la $a0, intArray    #the base address of the array and 
    lw $a1, size        #size are loaded into argument registers 

    jal search          #the function search is called and
    sw $v0, result      #the return value is store in result

    li $v0, 1           #result is printed to the screen
    lw $a0, result
    syscall

    li $v0, 10          #ends the programs
    syscall
	
search:                     #search

    addi $t0, $a0, 0        #the base address of the array is stored
    lw $t1, 0($t0)          #in $t0 and the value there is store in	
    addi $v0, $t1, 0        #$t1, while $t2 and $t5 are initialized	
    li $t2, 0               #to zero and 4
    li $t5, 1			
    sll $t5, $t5, 2

    Loop:	
	    slt $t3, $t2, $a1   #checks the counter $t2 against size in
	    bne $t3, 1, Exit    #$a1 and branches to Exit if it's not 
	    addi $t2, $t2, 1    #less than size	

	    slt $t3, $t1, $v0   #the lowest value so far in $v0 is 	
	    bne $t3, 0 Update   #checked against the value at the 
                            #current index and if that's smaller
                            #it goes to Update
	
	    add $t0, $t0, $t5   #the index of the array is advanced 
	    lw $t1, 0($t0)      #forward and it jumps back to Loop
	    j Loop

    Update:
        addi $v0, $t1, 0    #moves the new lowest value in $t1
        j Loop              #into $v0 and it jumps back to Loop

    Exit:
        jr $ra          #the function ends and control is
                        #returned to main

