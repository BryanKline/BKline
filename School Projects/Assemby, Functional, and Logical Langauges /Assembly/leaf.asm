#Bryan Kline
#CS219 HW #3
#02/27/2016
#3.

.data

    g:	.word 14
    h:	.word 15
    i:	.word 1
    k:	.word 21    #the variable j cannot be used as
    f:	.space 4    #j means jump in MIPS
	
.text

main:               #main

    lw $a0, g       #loads the data into argument
    lw $a1, h       #registers, gets the address of f 
    lw $a2, i       #and initializes f to zero
    lw $a3, k       #j must be called k as j will
    la $s0, f       #mean a jump in MIPS	 
    addi $s0, $s0, 0

    jal leaf        #calls function leaf

    sw $v0, 0($s0)  #stores the value returned
			        #from the function in f
			
    li $v0, 1       #prints f to the screen
    lw $a0, f	
    syscall

    li $v0, 10      #ends the program
    syscall
	
leaf:                   #leaf

    subiu $sp, $sp, 12  #grows the stack by three words
    sw $ra, 0($sp)      #and backs up $ra, $s0, and $s1		
    sw $s0, 4($sp)								
    sw $s1, 8($sp)	

    add $s0, $a0, $a1   #adds g and h, adds i and k (j), 
    add $s1, $a2, $a3   #then subtracts the results of
    sub $v0, $s0, $s1   #the two additions and stores the
			            #result in $v0

    lw $ra, 0($sp)      #the stack us shrunk by three words
    lw $s0, 4($sp)      #and the registers are restored
    lw $s1, 8($sp)
    addiu $sp, $sp, 12
																																																																																																						
    jr $ra      	    #the function ends and control is

                        #returned to main

