fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t) {
        val (a, b) = readLine()!!.split(" ").map{ it.toInt() }
        if(a * 2 <= b) {
            println("$a ${a*2}")
        }
        else {
            println("-1 -1")
        }
    }
}