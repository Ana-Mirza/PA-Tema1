##### Name: Ana-Maria Mirza
##### Group: 321CA


### Homework 1
#### Feribot

In order to find the minimum sum from the maximum of all individual sums of the feribots,
I used binary search between the maximum individual car weigth and the sum of all the weights.
If the cars could not be divided into k groups with sums less than or equal to the current sum,
I searched in the upper right side sums; otherwise, I searched in the lower left side and saved
every possible solution, so that at the end the returned solution is the smallest possible sum.

#### Nostory

##### Task 1
For the first task of getting the sum of the maxuimum n numbers from n pairs with unlimited number
of moves, I sorted all numbers and took the first n greatest numbers to compute the sum.

##### Task 2
For the second task, with limited number of moves, I took the numbers and sorted them decreasingly as
well, but retained their index number in order to ensure that only a number from a pair is taken. I took
the first n greatest numbers available to compute the sum this way: if the frequency vector with the 
given index of the current number was 0, the number was taken for the sum and the number in the frequency 
vector increased; if the frequency vector at the index position was different from 0, the pair was 
already used, meaning the other number from the pair was taken in the sum, if there were still moves 
available, the number was taken, otherwise it was ignored.

#### Sushi

##### Task 1
To compute the maximum grade possible with only 1 of each plate in the given price range, I computed the 
grade individually for each plate by summing the grade given by each friend. Then, I used the RUCSAC dp 
model to find the maximum grade.

##### Task 2
To compute the maximum grade possible with the possibility of taking 2 of each plate, I doubled the dp 
matrix in order to parse twice through each possible plate.

##### Task 3
To compute the maximum grade possible with eachc plate taken maximum 2 times and N plates in total, I 
used another dimension to limit the total number of plates possible. When computing the sum of the plates 
after adding the current plate, I used the matrix with (n - 1) possible plates to ensure that there are 
maximum n plates in total.

#### Semnale

##### Task 1
For this task, I computed the individual possibilities on the paper to find the dp recurrence, which is
the one written: dp[i][j - 1] + dp[i - 1][j - 1].

##### Task 2
For this task, the recurrence found, also through observance, was dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 2][j - 1].

#### BadGPT
I solved this problem by parsing the input string and ignoring all letters different from 'u' and 'n' 
becuase only they influenced the number of possibilities a string could be formed. When one of those 
letters was found in the string, I computed the number of times the letter appeared in a row, then found 
the recurrence for the number of strings possible for a 'u' or 'n' sequence to be dp[i - 1] + dp[i - 2]. 
In order to make it faster, I used matrix exponentiation, using the procedure presented in lab 4.
