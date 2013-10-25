Cat vs. Dog (Difficulty: Heavy metal)
==========
The latest reality show has hit the TV: “Cat vs. Dog”. In this show, a bunch of cats and dogs compete for the very prestigious Best Pet Ever title. In each episode, the cats and dogs get to show themselves off, after which the viewers vote on which pets should stay and which should be forced to leave the show.

Each viewer gets to cast a vote on two things: one pet which should be kept on the show, and one pet which should be thrown out. Also, based on the universal fact that everyone is either a cat lover (i.e. a dog hater) or a dog lover (i.e. a cat hater), it has been decided that each vote must name exactly one cat and exactly one dog.

Ingenious as they are, the producers have decided to use an advancement procedure which guarantees that as many viewers as possible will continue watching the show: the pets that get to stay will be chosen so as to maximize the number of viewers who get both their opinions satisfied. Write a program to calculate this maximum number of viewers.

Input
==========
On the first line one positive number: the number of testcases, at most 100. After that per testcase:

- One line with three integers c, d, v (1 ≤ c, d ≤ 100 and 0 ≤ v ≤ 500): the number of cats, dogs, and voters.
- v lines with two pet identifiers each. The first is the pet that this voter wants to keep, the second is the pet that this voter wants to throw out. A pet identifier starts with one of the characters ‘C’ or ‘D’, indicating whether the pet is a cat or dog, respectively. The remaining part of the identifier is an integer giving the number of the pet (between 1 and c for cats, and between 1 and d for dogs). So for instance, “D42” indicates dog number 42.

Output
==========
Per testcase:

One line with the maximum possible number of satisfied voters for the show.

 Sample Input 1  
 2  
 1 1 2  
 C1 D1  
 D1 C1  
 1 2 4  
 C1 D1  
 C1 D1  
 C1 D2  
 D2 C1  
 
 Sample Ouput 1  
 1  
 3
 
Solution
==========
If you read the problem carefully you will notice some clues:  
 1) Also, based on the universal fact that everyone is either a cat lover (i.e. a dog hater) or a dog lover (i.e. a cat hater), it has been decided that each vote must name exactly one cat and exactly one dog.  
 2) procedure which guarantees that as many viewers as possible will continue watching the show  
This points to finding the maximum matching in a bipartite graph  
http://en.wikipedia.org/wiki/Bipartite_graph

A) Create one list of cat lovers and one list of dog lovers 0(N).  
B) Using both lists construct a bipartite graph consisting of conflicting votes 0(m1*m2)  
C) Use Hopcroft-Karp algorithm to find the maximum matching for the bipartite graph 0(|E|\sqrt{|V|}).  
D) Since we need to find the max number of viewers then subtract the maximum matching value from the number of voters.  
E) Store this calculated value into a queue.  
F) Repeat for each test case.  
G) Print out queue.  
H) Bounce it… ones, fives, tens, twenties, you are DONE!!!!
