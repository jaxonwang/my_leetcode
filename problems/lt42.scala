import coolection.mutalbe.ArraySeq

object Solution{
  def trap(height: Array[Int]): Int = {
      
    var current_max_location = 0

    val max_before_l = for((x,i) <- height.view.zipWithIndex) yield {
      if (x >= height(current_max_location)) i else current_max_location
    }
    val max_before = max_before_l.toArray

    val max_water = new ArraySeq(height.size)

    for(i <- 1 to height.size){


    }


    123
    }
}

println(Solution.trap(Array(0,1,0,2,1,0,1,3,2,1,2,1)))
