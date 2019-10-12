/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (42.55%)
 * Total Accepted:    53.4K
 * Total Submissions: 125.6K
 * Testcase Example:  '26'
 *
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 *
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 *
 *
 *
 * Example 2:
 *
 * Input:
 * -1
 *
 * Output:
 * "ffffffff"
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convert(unsigned char ch) {
    if (ch > 15) {
        return 0;
    } else if (ch >= 10) {
        return 'a' + ch - 10;
    } else {
        return '0' + ch;
    }
}

char *toHex(int num) {
    char *res = (char *)malloc(sizeof(char) * 9);
    if (num == 0) {
        res[0] = '0';
        return res;
    }
    unsigned char *a = (unsigned char *)malloc(sizeof(int));
    memcpy(a, &num, sizeof(int));
    a = a + 3;
    // unsigned char *a = (char *)&num + 3;
    // pos is used to locate the position and know whether it is first one
    int pos = 0;
    for (int i = 0; i < 4; i++) {
        char ch0 = convert(a[-i] >> 4);
        char ch1 = convert(a[-i] & 0x0f);
        if (pos == 0) {
            if (ch0 == '0') {
                if (ch1 == '0') {
                    continue;
                }
                res[pos++] = ch1;
            } else {
                res[pos++] = ch0;
                res[pos++] = ch1;
            }
        } else {
            res[pos++] = ch0;
            res[pos++] = ch1;
        }
    }
    return res;
}

int main() {
    printf("%s\n", toHex(-1));
    printf("%s\n", toHex(26));
    return 0;
}
