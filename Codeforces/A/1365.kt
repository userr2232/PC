import kotlin.math.*

fun main() {
    var t = readLine()!!.toInt()
    for(i in  1..t) {
        var (n, m) = readLine()!!.split(" ").map{ it.toInt() }
        var table = Array(n, {IntArray(m)})
        var rowsTaken = 0
        var columnsTaken = 0
        for(j in 0..n-1) {
            table[j] = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
            var x = table[j].indexOfFirst{ v -> v == 1 }
            if(x != -1)
                rowsTaken++
        }
        for(j in 0..m-1) {
            for(k in 0..n-1) {
                if(table[k][j] == 1) {
                    columnsTaken++
                    break
                }
            }
        }
        var optimal = min(m - columnsTaken, n - rowsTaken)
        if(optimal % 2 == 1)
            println("Ashish")
        else
            println("Vivek")
    }
}