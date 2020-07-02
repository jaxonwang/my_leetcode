import scala.collection.mutable.SortedMap
import scala.collection.mutable.ArrayBuffer
import scala.util.matching.Regex

object Parse{

def twoDtoArray(s:String) :Array[Array[Int]]= {
  val sss = s.slice(1, s.size-1)
  val rg = new Regex(raw"\[(.*?)\]")

  var a = ArrayBuffer[Array[Int]]()
  for(p <- rg.findAllMatchIn(sss)){
    // println(s"${p.group(1)} ${p.group(3)}")
    for(g<-p.subgroups){
      val tmp = g.split(",").map(_.trim().toInt)
      a += tmp
    }
  }
  return a.toArray
}

def printArray(a:Array[Int]){
  println(a.mkString(" ") )
}

def print2DArray(a:Array[Array[Int]]){
  a.foreach(printArray)
}
}


object Solution {
    def maxEnvelopes(envelopes: Array[Array[Int]]): Int = {
      val envs= envelopes.sortWith((a,b)=>if (a(0)==b(0)) a(1) > b(1) else a(0) < b(0))
      val m = SortedMap[Int,Int]() // tail, length
      val lis_tail = Array.fill(envs.size + 1){0}// length, tail
      for(i <- envs.indices){
        val key = envs(i)(1)
        val l = m.maxBefore(key) match{
          case Some(_ -> length) => length + 1
          case None => 1
        }
        if(lis_tail(l) ==0 || lis_tail(l) > key){
          m -= lis_tail(l)
          lis_tail(l) = key
          m += (key -> l)
        }
      }
      if(!m.isEmpty)m.max._2 else 0
    }
    def lengthOfLIS(nums: Array[Int]): Int = {
      val m = SortedMap[Int,Int]() // tail, length
      val lis_tail = Array.fill(nums.size + 1){0}// length, tail
      for(i <- nums.indices){
        val key = nums(i)
        val l = m.maxBefore(key) match{
          case Some(_ -> length) => length + 1
          case None => 1
        }
        if(lis_tail(l) ==0 || lis_tail(l) > key){
          m -= lis_tail(l)
          lis_tail(l) = key
          m += (key -> l)
        }
      }
      if(!m.isEmpty)m.max._2 else 0
    }
}
Solution.lengthOfLIS(Array(10,9,2,5,3,7,101,18))
val input = "[[4,5],[4,6],[6,7],[2,3],[1,1]]"
val a = Parse.twoDtoArray(input)
println( Solution.maxEnvelopes(a))
