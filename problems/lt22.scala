import scala.collection.mutable.Map

object Solution extends App{
  var r: Map[Int, List[String]] = Map()
  def getv(i :Int) = if (r.contains(i)) r(i) else {
    r.put(i, generateParenthesis(i))
    r(i)
  }

  def generateParenthesis(n: Int): List[String] = n match{
    case 0 => List[String]("")
    case _ => (for {i <- List.range(0, n)}yield{
      val left = getv(i)
      val right = getv(n-i-1)
      for{j <- getv(i);k <-getv(n-i-1)} yield ("(" + j + ")" + k)
    }).foldLeft(List[String]())(_ ++ _)
  }
  println(generateParenthesis(4))
}
