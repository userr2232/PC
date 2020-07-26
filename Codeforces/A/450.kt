fun main() {
    var (n, m) = readLine()!!.split(" ").map{ it.toInt() }
    readLine()!!.split(" ").map{ it.toInt() }.toMutableList().let {
        var last = 0;
        while(true) {
            var count = 0
            for((i, x) in it.withIndex()) {
                if(x > 0) {
                    it[i] -= m
                    last = i + 1
                }
                if(it[i] <= 0) count++
            }
            if(count == n) break
        }
        println(last)
    }
}