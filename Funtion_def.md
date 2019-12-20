# C-Project

## 图书馆信息管理系统

### 函数接口定义：

#### 定义于 `backend.cpp`

  
#####  `int isISBNCorrect(char ISBN[20], int WillCorrect);`

  检查并更正ISBN号码。
  
#####  参数：
  
  `char ISBN[20]` ：传入存放ISBN的数组。
  
  `int WillCorrect`: 选择是否更正ISBN末位校验码。**可选值：`0` 或 `1`**
  
  1 - 自动更正ISBN的末位校验码。
  
  0 - 不更正ISBN的末位校验码。
  
#####  返回值: 
  
  当前ISBN是否正确。**可能的值：`0` ， `1` 或 `2`**
  
  `0` : 当前ISBN不正确， 且未被更正。
  
  `1` : 当前ISBN正确， 或已被更正为正确的值。
  
  `2` : 未知错误。
  
  --
  
  `void OutputList(FILE * fileW, struct Book * head);`
  
  输出当前的书籍列表到标准输出或指定的文件流。
  
  
  
  
  struct Book * CreateList(FILE * fileR);
  struct Book * DeleteItem(struct Book * cur);
  struct Book * DeleteList(struct Book * cur);
  void OutputItem(FILE * fileW, struct Book * cur);
  int QueryByNo(FILE * fileR, struct Book * head, int No);
  void BubbleSortByNo(struct Book * head, char op);
  struct Book * AddBooks(FILE * fileR, struct Book * head);
  struct Book * DeleteBooksByNo(struct Book * head, int No);