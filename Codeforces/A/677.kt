fun main() {
    var (n, h) = readLine()!!.split(" ").map{ it.toInt() }
    var ans = 0
    var l = readLine()!!.split(" ").map{ it.toInt() }
    l.forEach{
        if(it > h)
        ans++
    }
    ans += l.size
    println(ans)
}