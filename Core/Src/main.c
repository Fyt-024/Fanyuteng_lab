#include "stm32f4xx.h"

int main(void)
{
    // 1. 打开GPIOB时钟 (AHB1)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // 2. 配置PB0/1/2/6/7/14为推挽输出
    //    (每个引脚MODE寄存器置 '01')
    GPIOB->MODER |= (1U << (0 * 2))   // PB0
                 |  (1U << (1 * 2))   // PB1
                 |  (1U << (2 * 2))   // PB2
                 |  (1U << (6 * 2))   // PB6
                 |  (1U << (7 * 2))   // PB7
                 |  (1U << (14 * 2)); // PB14
    //  其他如 OTYPER/OSPEEDR/PUPDR 在多数情况下可默认值即可

    // 3. 设置输出高电平 => 常亮
    //    这里直接往BSRR的低16位写1即可把对应引脚置高
    GPIOB->BSRR = (1U << 0)   // PB0
                | (1U << 1)   // PB1
                | (1U << 2)   // PB2
                | (1U << 6)   // PB6
                | (1U << 7)   // PB7
                | (1U << 14); // PB14

    while(1)
    {
        // 什么都不做
    }
}