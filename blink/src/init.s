.section ".init"
.global init

init:
    ldr r0, =__stack_base
    bl  main
    b   .
