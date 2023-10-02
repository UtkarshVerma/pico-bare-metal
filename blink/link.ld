OUTPUT_FORMAT("elf32-littlearm")
ENTRY(init)

MEMORY {
    flash(rx) : ORIGIN = 0x1000000, LENGTH = 0xfc
}

SECTIONS {
    /* .init contains initialisation routines. */
    .init : {
        __stack_base = ORIGIN(flash);
        *(.init)
    } > flash

    /* .text contains the compiled C code. */
    .text : { *(.text*) } > flash

    /*
     * Discard unnecessary sections from the ELF.
     *     .comment: includes compiler metadata
     *     .ARM.attributes: ARM-specific binary metadata
     */
    /DISCARD/ : { *(.comment) *(.ARM.attributes) }
}
