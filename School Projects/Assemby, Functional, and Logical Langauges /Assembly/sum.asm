#Bryan Kline
#CS219 HW #3
#02/27/2016
#1.

.data
    number:     .word 0
    result:     .word 0
	
.text

main:               #main

    li $v0, 5       #gets a value from the user and		
    syscall         #stores it in number
    sw $v0, number

    lw $a0, number  #puts number into $a0 and jumps 
    jal sum         #and links to sum and saves the
    sw $v0, result  #returned value in result

    li $v0, 1       #prints result to the screen
    lw $a0, result
    syscall

    li $v0, 10      #ends the program
    syscall
		
sum:                    #the sum function 
	
    subiu $sp, $sp, 8   #grows the stack by two words 
    sw $ra, 0($sp)      #and stores $ra and #s0 ($t0 could
    sw $s0, 4($sp)      #be used instead, but I'm just doing
                        #this to show that I know a function
                        #must restore $s0-$s7)

    li $v0, 0           #loads a default of zero into $v0 and
    beq $a0, 0, Done    #checks whether $a0 is equal to zero
                        #if so then it jumps to done	
			
    addi $s0, $a0, 0    #moves $a0 into $s0 and then subtracts
    addi $a0, $a0, -1   #one from $a0 and then jumps and links
    jal sum             #back to sum with decremented $a0

    add $v0, $s0, $v0   #adds the value in $s0 and $v0 
	
    Done:
	
        lw $ra, 0($sp)      #gets $ra and #sp back from the stack
        lw $s0, 4($sp)      #shrinks the stack by two words and
        addiu $sp, $sp, 8   #the jumps back to main
        jr $ra

