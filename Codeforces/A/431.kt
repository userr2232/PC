fun main() {
    var l = readLine()!!.split(" ").map{ it.toInt() }
    var cost = 0
    readLine()!!.map{ it.toString().toInt() }.forEach{ it ->
        cost += l[it - 1]
    }
    println(cost)
}