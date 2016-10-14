# Naive-Bayes-Classification
Implementation of Naive Bayes Classification for classifying data using supervised learning

Consists of the following two files.

###NBC.CPP

This file consists of the code that

1. Accepts the training data from the user and considers the last column to be the class.

2. Calculates the probabilities.

3. Accepts the tupple to be classified.

4. Classifies using the formula and displays the outpu.

###IP.in

This is the input file.

Line 1 - Number of Training Tupples

Line 2 - Number of Columns

Line 3 to 24 - Accepts the name for each column, the number of distinct inputs it can have, the inputs themselves.

Line 25 to 94 - Inputs in the form of whole numbers representing each choice for the given column.*

Line 95 - The column of the class.**

Line 96 to 99 - Input of the tupple to be classified.

*The given input is for the following data:-

| Age | Income | Student | Credit Rating | Buys Computer(Class) |
| --- | --- | --- | --- | --- |
| <=30 |	High	| No	| Fair	| No |
| <=30	| High	| No	| Excellent	| No |
| 31…40	| High	| No	| Fair	| Yes |
| >40	| Medium	| No	| Fair	| Yes |
| >40	| Low	| Yes	| Fair	| Yes |
| >40	| Low	| Yes	| Excellent	| No |
| 31…40	| Low	| Yes	| Excellent	| Yes |
| <=30	| Medium	| | No	| Fair	| No |
| <=30	| Low	| Yes	| Fair	| Yes |
| >40	| Medium	| Yes	| Fair	| Yes |
| <=30	| Medium	| Yes	| Excellent	| Yes |
| 31…40	| Medium	| No	| Excellent	| Yes |
| 31…40	| High	| Yes	| Fair	| Yes |
| >40	| Medium	| No	| Excellent	| No |

**The code will work only when the class is the last column. So enter accordingly.
age	income	student	credit_rating	buys_computer
