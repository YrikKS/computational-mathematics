fun main(args: Array<String>) {
    `first test`()
    `second test`()
    `third test`()
}

fun `first test`() {
    val n = 6
    val aFunc = { _: Int -> -1.0 }
    val bFunc = { _: Int -> -1.0 }
    val cFunc = { _: Int -> 2.0 }
    val vectorFunc = { _: Int -> 2.0 }
    var f = Vector(n, vectorFunc)
//    f.printVector()
    var matrix = Matrix(n, aFunc, bFunc, cFunc)
//    matrix.printMatrix()
    RunThroughMethod(matrix, f).startMethod().printVector()
}

fun `second test`() {
    val epsilon = 0.1
    val n = 6
    val aFunc = { _: Int -> -1.0 }
    val bFunc = { _: Int -> -1.0 }
    val cFunc = { _: Int -> 2.0 + epsilon }
    val vectorFunc = { _: Int -> 2.0 }
    var f = Vector(n, vectorFunc)
//    f.printVector()
    var matrix = Matrix(n, aFunc, bFunc, cFunc)
//    matrix.printMatrix()
    RunThroughMethod(matrix, f).startMethod().printVector()
}

fun `third test`() {
    val gamma = 2.1
    val n = 6
    val aFunc = { _: Int -> -1.0 }
    val bFunc = { _: Int -> -1.0 }
    val cFunc = { index: Int -> 2.0 * index + gamma }
    val vectorFunc = { index: Int -> 2.0 * (index + 1) + gamma }
    var f = Vector(n, vectorFunc)
//    f.printVector()
    var matrix = Matrix(n, aFunc, bFunc, cFunc)
//    matrix.printMatrix()
    RunThroughMethod(matrix, f).startMethod().printVector()
}