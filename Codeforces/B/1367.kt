fun main() {
    var t = readLine()!!.toInt()
    for(k in 1..t) {
        readLine()
        var evens = 0
        var odds = 0
        readLine()!!.split(" ").map{ it.toInt() }.forEachIndexed{ i, x ->
            if(i%2 == 0 && x%2 == 1) evens++
            if(i%2 == 1 && x%2 == 0) odds++
        }
        if(evens != odds) println(-1)
        else println(evens)
    }
}