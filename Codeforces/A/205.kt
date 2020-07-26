fun main() {
    readLine()
    var min = Int.MAX_VALUE
    var index = 0
    var count = 0
    readLine()!!.split(" ").map{ it.toInt() }.forEachIndexed { i, x ->
        if (x < min) {
            min = x
            index = i
            count = 0
        }
        else if (x == min) {
            count++
        }
    }
    if(count > 0)
        println("Still Rozdil")
    else
        println(index + 1)
}