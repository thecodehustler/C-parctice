#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include <ctype.h>
#include <stdbool.h>

/**
 * Note: 这并不是最高效的处理方法。
 * 
 * 验证字串是否是二叉树的前序遍历结果。
*/
bool isValidSerialization(char* preorder) {
  const int len = strlen(preorder);

  int* stack = (int*) calloc(len, sizeof(int));
  int top = 0; // 指向栈的“超尾”，即下一个空余位置。
  int state = 0; // 处理多位数字。

  int i = 0; 
  while (i < len) {
    const char ch = preorder[i++];
    
    if (ch == ',') {
      state = 0;
    }

    else if (isdigit(ch)) { // 是一位数字。
      if (state == 0) {
        stack[top++] = 0;
        state++;
      }
    } else if (ch == '#') { // 是 nullptr。
      state = 0;
      if (top > 0) { // 如果栈不是空的。
        stack[top - 1]++; // 已遍历的分支计数 + 1；
      }
    }
    while (top > 0 && stack[top - 1] == 2) { // 检查栈顶，如果已遍历计数为 2，说明对应的节点已经完成了前序遍历。
      if ((--top) > 0) { // 将这个节点的孩子计数退栈
        stack[top - 1] += 1; // 栈中上一个节点的已遍历计数 +1；
      }
    }
    if (top == 0) { // 已经完整的遍历了一棵树。
      break; // 提前退出就可以了。
    }
  }
  free(stack);

  return (i == len) && top == 0; // 没有遍历完，或者遍历完之后栈里还有东西的时候就返回 false。
}

int main() {
  printf("%d\n", isValidSerialization("1,#,#"));
  printf("%d\n", isValidSerialization("1,#"));
  printf("%d\n", isValidSerialization("12,#,#,1,1"));

  return 0;
}