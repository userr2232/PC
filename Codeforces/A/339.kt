fun main() {
    var x = readLine()!!.split("+").toMutableList()
    x.sort()
    println(x.joinToString("+"))
}