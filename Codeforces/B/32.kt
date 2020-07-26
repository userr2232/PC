fun main() {
    readLine()!!.let {
        var i = 0
        while(i < it.length) {
            if(it[i] == '.')
                print(0)
            else {
                if(it[i] == '-' && it[i + 1] == '.') print(1)
                else print(2)
                i++
            }
            i++
        }
    }
    println()
}