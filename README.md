# MinMaxSpeedTest
This project grew from my curiosity during my Discrete Mathematics class. That class dealt a lot with combinatorics and so at one point it had gone into divide-and-conquer algorithms. I had already known about divide-and-conquer algorithms from my Data Structures and Algorithms class but something in the book caught my eye. The book went over a basic divide-and-conquer algorithm to find the minimum and maximum elements of a randomly sorted array. If asked how I would find the minimum and maximum elements of an array, I would probably just loop through the list twice. At best, I would loop through the array once and make two comparisons on each element, and this is because it's easy to do in a few lines of code. The book claimed a divide-and-conquer algorithm could find both minimum and maximum elements with three-halves the comparisons instead of twice the comparisons. This seemed interesting to me so I set out to test that theory and see if it was truly faster than the lazy-loop method. 

## Summary of Lazy-Loop Method
The lazy-loop method is about 5 lines of code. 2 lines to declare your min and max variables, 1 line for the loop, and 2 lines to compare the current element to the most-recent min and max. 

## Summary of Divide-and-Conquer Method
The divide and conquer method is simple. Divide the array in halves until you reach two elements. Find the minimum of these two elements and make the other the maximum (one comparison). Then work your way up comparing only the minimums to the minimums and the maximums to the maximums. You can see that this saves time from the lazy-loop method because in the lazy-loop method I compare each element twice whereas in the divide-and-conquer method I don't bother to compare the minimums to the maximums. 

## Complications
Clearly there is a major difference between theory and implementation. One complication that I immediately saw was the the overhead associated with a recursive divide-and-conquer function. Unless the divide-and-conquer version was significantly faster than the iterative (for example O(n) vs O(n<sup>2</sup>)), the iterative version would probably win simply because it doesn't have to deal with creating and deleting activation records, jumping addresses, etc. In addition to this, the iterative version was better for cache since each comparison was done local to the next. 

## Solution
To create a solution that was capable of beating my lazy-loop method I would need to convert the divide-and-conquer recursive solution into an iterative one. This doesn't always work out and many times you end up with an algorithm that doesn't match the original specification. In this case, the solution is close enough. 

To make this conversion, I had to find what the base case was. The base case of the divide-and-conquer method is when there are only two elements. Looking at it this way, the method goes as follows:

* Find the minimum of the pair
* Compare the minimum we found just now to the minimum so far
* Compare the other element (implied to be the maximum) to the maximum so far

As you can see we make 3 comparisons per 2 elements, this makes it easy to see where the three-halves figure comes from. 

This new algorithm relies on the array being even because of the pairs of two. Here's how to proceed:

* If odd, our first element will be our default min and max and the remaining pairs will follow the algorithm
* If the array is even, find the minimum of the first pair, and continue with the algorithm 

## Implementation details of the code
You'll notice if you look at my code that while I have a function that will generate a random array of some size provided by the user, I have this commented out and instead use the calloc() function setting every position to zero. This is because creating a random array takes far too long for large values for size and was getting in the way of the algorithm (which goes in not knowing the entire array is all zero's anyways). Note that the random array function just shuffles the numbers 1 through n, n times.

## Results
The results of this solution were about what you would expect. The resulting comparisons would always come out to exactly three-halves the comparisons of n (rounded up) whereas the result of the lazy-loop method always came out to double the comparisons of n. The time that the two took was proportional to the number of comparisons, 3:4 (or 1.5:2). Below is a pretty graph showing the difference in times and comparisons between the two for various sized inputs. 

<img src="https://i.imgur.com/i5l6VcI.png">

## Conclusion
While the divide-and-conquer method is technically faster than the lazy-loop method, it doesn't make a whole lot of difference. The additonal lines of code are also a pain to write. Unless this function was needed for something on an extremely massive scale this is a total waste of time and effort...but at least you (and I) know that now. 
