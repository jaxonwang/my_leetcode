
def permute(nums: Array[Int]): List[List[Int]] = {
  return dopermute(nums.toList)  
}

def dopermute(nums: List[Int]):List[List[Int]] = nums match{
  case Nil => Nil::Nil
  case head::tail => {
    val lists = dopermute(tail).map(head::_)
    def swap(i:Int, j:Int, _nums:List[Int]) = if (i !=j && _nums(i)==_nums(j)) Nil else _nums.updated(i, _nums(j)).updated(j, _nums(i))
    val tmp = for {i <- List.range(0,nums.length); list <- lists} yield swap(0, i, list)
    val tmp1 = tmp.filter(_ != Nil)
    println(tmp1)
    tmp1
  }
}

val a = permute(Array(1,1,3))
println(a)


