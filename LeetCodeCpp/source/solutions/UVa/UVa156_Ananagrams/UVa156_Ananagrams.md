UVa 156 "Ananagrams"

题目描述：

给定一些单词，统计它们出现的次数，如果一个单词是另一个单词的字母重排列而成的，就不算作一个独立的单词。最后输出仅出现一次且不是其他单词的字母重排列的单词，按字典序排序。单词大小写不敏感。

输入格式：

多组输入，每行输入若干个单词（可能有空格），以 # 结尾。每个单词长度不超过100。

输出格式：

输出所有符合条件的单词，每个单词占一行。如果没有符合条件的单词，则输出一行空白。

样例输入：

ladder came tape soon leader acme RIDE lone Dreis peat ScAlE orb eye Rides dealer NotE derail LaCeS drIed noel dire Disk mace Rob dries

样例输出：

Disk

leader

soon

样例说明：

输入共有13个单词，其中not和ton、noel和lone、note和tone、lacer和clear、scale和laces是字母重排列，应被归为一类。符合条件的单词有Disk、leader和soon。