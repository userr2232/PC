import kotlin.math.*

fun main() {
    var x = -1
    var y = -1
    for(i in 1..5) {
        val s = readLine()!!
        if(x == -1) {
             x = s.split(" ").map{ it.toInt() }.indexOf(1)
             if(x != -1) {
                x += 1
                y = i
             }
        }
    }
    println(abs(3 - x) + abs(3 - y))
}