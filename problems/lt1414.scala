object Solution {

    def findMinFibonacciNumbers(k: Int): Int = {
      return dofind(k, 1, 1)._2
    }

    def dofind(k: Int, i: Int, j:Int): (Int, Int)={
      if (k < j)
        return (k -i, 1) 
      dofind(k, j, i+j) match{
        case (re, ops) => if (re < i) (re, ops) else (re -i, ops +1)
      }
    }
}

val a = Solution.findMinFibonacciNumbers(19)
println(a)
