
簡易版C語言Interpreter  
使用語言:C++  
編譯器: DevC
===========================
****
## 目錄
* [介紹](#介紹)
* [功能](#功能)
* [範例(基本功能)](#基本功能範例)
* [範例(複雜示範)](#複雜範例)

------------------------------------------------------  

介紹
----
Project1為 基礎的運算能力及變數宣告  
Project2為 C語言文法的check  
Project3為 2的進階 除了確認文法的正確性還要加上運算能力及輸出答案  
Porject4為 3的進階 要加入Call function的能力  



------------------------------------------------------

功能
----  
1.可以根據輸入的字串 判斷是否為正確的C語言文法及輸出運算    
(基本上大部分的C文法都能接受)  
2.程式開始前要先隨便輸入一個數字 然後按enter後才算開始執行  
3.程式結束以輸入 Done();  為結束  
4.可接受 變數宣告.function宣告.陣列宣告及運算.條件式.迴圈等等運算能力  
5.提供 ListVariable("變數名稱")、ListAllVariables()、
       ListFunction("名稱")、ListAllFunctions() 等4個額外輸入  
6.輸入錯誤時會印出對應的錯誤行數  
7. Error可以分出是lexical error(不接受的token @#$等等)、syntactic error(文法錯誤)、 semantic error(呼叫未宣告變數)  
8.輸出部分除了第5點所提及的功能及error訊息外 皆在Done(); 之後輸出  
因為做法事 採用先檢查一遍文法正確 將正確文法存下後 第二遍才跑運算的部分  
而不是一邊檢查文法一邊運算  
9. 變數宣告可以判別出是否有宣告過

------------------------------------------------------

基本功能範例
----
1-
![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B%EF%BC%91.png)

1-1

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B1-1.png)

1-2

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B1-2.png)

2-1

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B2-1.png)

2-2

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B2-2.png)
3-1

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B3-1.png)

3-2

![image](https://github.com/WaiXuan/C-Interpreter/blob/12c9f0db47e85997af8cfdcccd73ebb156cb4edf/Image/%E7%AF%84%E4%BE%8B3-2.png)
------------------------------------------------------








