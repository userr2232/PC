fun main() {
    readLine()
    val nums = readLine()!!.split(" ")
    var fives = nums.count{ it == "5" }
    val zeros = nums.count{ it == "0" }
    fives -= fives % 9
    if(zeros > 0) {
        if(fives > 0)
            println("5".repeat(fives) + "0".repeat(zeros))
        else
            println(0)
    }
    else {
        println(-1)
    }
}