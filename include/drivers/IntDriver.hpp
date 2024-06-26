#pragma once

#include <stdint.h>

typedef struct {
    uint32_t ds;
    uint64_t r15, r14, r13, r12, r11, r10, r9, r8, rdi, rsi, rbp, rsp, rbx, rdx, rcx, rax;
    uint32_t int_no, err_code;                        // interrupt number and error code
    uint32_t eip, cs, eflags, useresp, ss;            // pushed by the processor automatically
} REGISTERS;

typedef void (*ISR)(REGISTERS *);

class intDriver {
private:
    void set_idtEntry(int index, uint64_t base);

public:

    void register_Handler(int num, ISR handler);

    intDriver();

    void init();
};

extern intDriver IntDriver;

// excpetions

extern "C" void exception0();
extern "C" void exception1();
extern "C" void exception2();
extern "C" void exception3();
extern "C" void exception4();
extern "C" void exception5();
extern "C" void exception6();
extern "C" void exception7();
extern "C" void exception8();
extern "C" void exception9();
extern "C" void exception10();
extern "C" void exception11();
extern "C" void exception12();
extern "C" void exception13();
extern "C" void exception14();
extern "C" void exception15();
extern "C" void exception16();
extern "C" void exception17();
extern "C" void exception18();
extern "C" void exception19();
extern "C" void exception20();
extern "C" void exception21();
extern "C" void exception22();
extern "C" void exception23();
extern "C" void exception24();
extern "C" void exception25();
extern "C" void exception26();
extern "C" void exception27();
extern "C" void exception28();
extern "C" void exception29();
extern "C" void exception30();
extern "C" void exception31();
extern "C" void exception128();

// irqs
extern "C" void irq0();
extern "C" void irq1();
extern "C" void irq2();
extern "C" void irq3();
extern "C" void irq4();
extern "C" void irq5();
extern "C" void irq6();
extern "C" void irq7();
extern "C" void irq8();
extern "C" void irq9();
extern "C" void irq10();
extern "C" void irq11();
extern "C" void irq12();
extern "C" void irq13();
extern "C" void irq14();
extern "C" void irq15();