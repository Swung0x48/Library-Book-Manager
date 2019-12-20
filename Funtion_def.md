# C-Project

## 图书馆信息管理系统

### 函数接口定义：

#### 定义于 `backend.cpp`

  
#####  `int isISBNCorrect(char ISBN[20], int WillCorrect);`

  检查并更正ISBN号码。
  
#####  参数：
  
  `char ISBN[20]` - 传入存放ISBN的数组。
  
  `int WillCorrect` - 选择是否更正ISBN末位校验码。**可选值：`0` 或 `1`**
  
  `1` - 自动更正ISBN的末位校验码。
  
  `0` - 不更正ISBN的末位校验码。
  
#####  返回值: 
  
  当前ISBN是否正确。**可能的值：`0` ， `1` 或 `2`**
  
  `0` - 当前ISBN不正确， 且未被更正。
  
  `1` - 当前ISBN正确， 或已被更正为正确的值。
  
  `2` - 未知错误。
  
  ---
  
#####  `void OutputList(FILE * fileW, struct Book * head);`
  
  输出指定的书籍列表到标准输出或指定的文件流。
  
#####  参数：
  
  `FILE * fileW` - 指定要输出到的文件流。 对于标准输出， 请传入`stdout`。
  
  `struct Book * head` - 传入要输出的图书列表的头指针。
  
#####  返回值：

  无返回值。
  
  ---
  
#####  `struct Book * CreateList(FILE * fileR);`
  
  从标准输入或指定的文件流创建书籍列表。
  
##### 参数：

  `FILE * FileR` - 指定从哪个文件流读入书籍列表。对于标准输入，请传入`stdin`。
  
#####  返回值：

  无返回值。
  
  ---
  
#####  `void OutputItem(FILE * fileW, struct Book * cur);` [1]
  
  将指定的某本书籍信息输出到指定的文件流或标准输出。
  
##### 参数：

  `FILE * fileW` - 指定将书籍信息输出到哪个文件流。对于标准输出，请传入`stdout`。
  
  `struct Book * cur` - 指向指定书籍的指针。
  
#####  返回值：

  无返回值。
  
  ---
  
#####  `int QueryByNo(FILE * fileR, struct Book * head, int No);`
  
  通过图书在系统的编号查询某本书，并输出到指定的文件流或标准输出。
  
##### 参数：  
  
  `FILE * fileR` - 指定将查询结果输出到哪个文件流。对于标准输出，请传入`stdout`。
  
  `struct Book * head` - 传入要输出的图书列表的头指针。
  
  `int No` - 指定要查询的图书编号。
  
##### 返回值：

  是否成功完成查询并输出。
  
  `0` - 成功从列表中找到对于的书籍并输出。
  
  `1` - 成功从列表中找到对于的书籍并输出。对应的书籍可能不存在。
  
  ---
  
#####  `void BubbleSortByNo(struct Book * head, char op);`
  
  以编号为依据对书籍列表进行排序。
  
##### 参数：

  `struct Book * head` - 传入要进行操作的图书列表的头指针。
  
  `char op` - 选择进行升序或降序排序书籍。**可选值：`'<'` 或 `'>'`**
  
  `'<'` - 以升序排序图书列表。
  
  `'>'` - 以降序排序图书列表。
  
##### 返回值：

  无返回值。
  
  ---
  
#####  `struct Book * AddBooks(FILE * fileR, struct Book * head);` [2]
  
  从指定的文件流或标准输入读入书籍列表并添加进已有列表。
  
##### 参数：

  `FILE * fileR` - 指定从哪个文件流读入列表。对于标准输入，请传入`stdin`。
  
  `struct Book * head` - 传入要添加的图书列表的头指针。
  
##### 返回值：

  `struct Book * head` - 返回操作完成后的列表的头指针。
  
  ---
  
#####  `struct Book * DeleteBooksByNo(struct Book * head, int No);` [2]
  
##### 参数：
  
  `struct Book * head` - 传入要删除的图书列表的头指针。
  
  `int No` - 要删除的书籍在系统的编号。
  
##### 返回值：

  `struct Book * head` - 返回操作完成后的列表的头指针。
  
  ---
  
  [1] 请不要调用这些函数，除非你很熟悉链表并且知道自己在干什么！
  
  [2] 建议与BubbleSortByNo()一起使用。