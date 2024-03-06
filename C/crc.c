#include <stdint.h>
#include <stdio.h>
#include <string.h>

// 定义CRC8多项式（例如：0x31 对应 X^8 + X^2 + X + 1）
#define CRC8_POLYNOMIAL 0x31

// 初始化CRC寄存器的值
#define INITIAL_CRC_VALUE 0x00

// 将一个无符号整数值（以bit为单位）转换为小端序字节数组，并返回实际使用的字节数
size_t int_to_byte_array(uint64_t value, size_t bit_width, uint8_t byte_array[8]) {
    size_t length = (bit_width + 7) / 8;
    for (size_t i = 0; i < length; ++i) {
        byte_array[i] = (value >> (i * 8)) & 0xFF;
    }
    return length;
}

// 计算单个数据段的CRC8校验值
uint8_t crc8_calculate(const uint8_t* data, size_t length) {
    uint8_t crc = INITIAL_CRC_VALUE;

    for (size_t i = 0; i < length; ++i) {
        crc = crc ^ data[i];
        for (uint8_t bit = 8; bit > 0; --bit) {
            if (crc & 0x01) {
                crc = (crc >> 1) ^ CRC8_POLYNOMIAL;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

// 计算多个信号组合在一起的CRC8校验值
uint8_t crc8_calculate_multiple_signals(struct SignalInfo signals[], size_t num_signals) {
    uint8_t total_crc = INITIAL_CRC_VALUE;
    uint8_t* combined_data = (uint8_t*) malloc(sizeof(signals[0].signal) * num_signals);

    // 将所有信号数据合并到一个连续的数据块中
    size_t combined_length = 0;
    for (size_t i = 0; i < num_signals; ++i) {
        memcpy(combined_data + combined_length, signals[i].signal, signals[i].length);
        combined_length += signals[i].length;
    }

    // 计算整体CRC8校验值
    total_crc = crc8_calculate(combined_data, combined_length);

    free(combined_data);
    return total_crc;
}

int main() {
    // 假设我们有200个不同的信号，每个信号的位宽不同
    struct SignalInfo {
        uint8_t signal[8]; // 假设最大允许存储8字节
        size_t length;
        size_t bit_width;
    };

    struct SignalInfo signals[200];
    const size_t signal_bit_widths[200] = {
        // 示例填充200个信号的位宽（这里仅填充前几个作为演示）
        9, // 第一个信号是9bit
        8, // 第二个信号是8bit
        // ... 其他198个信号的位宽 ...
        16 // 第200个信号是16bit
    };

    // 循环将信号转换为字节数组并存储到signals数组中
    for (size_t i = 0; i < sizeof(signals) / sizeof(signals[0]); ++i) {
        signals[i].bit_width = signal_bit_widths[i];
        signals[i].length = int_to_byte_array(1UL << signal_bit_widths[i], signal_bit_widths[i], signals[i].signal); // 这里使用了示例值，您可以替换为实际的大数值信号
    }

    // 计算所有信号组合起来的CRC8校验值
    uint8_t total_crc = crc8_calculate_multiple_signals(signals, sizeof(signals) / sizeof(signals[0]));

    printf("Calculated total CRC8: 0x%02X\n", total_crc);

    return 0;
}