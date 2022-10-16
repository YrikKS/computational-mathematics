class Matrix(sizeMatrix: Int, a: (Int) -> Double, b: (Int) -> Double, c: (Int) -> Double) {
    private val matrix = Array(sizeMatrix) { DoubleArray(sizeMatrix) }

    init {
        for (index in matrix.indices) {
            matrix[index][index] = c(index)
            when (index) {
                0 -> matrix[index][index + 1] = (-1.0)*b(index)
                matrix.size - 1 -> matrix[index][index - 1] = (-1.0)*a(index)
                else -> {
                    matrix[index][index - 1] = (-1.0)*a(index)
                    matrix[index][index + 1] = (-1.0)*b(index)
                }
            }
        }
    }

    fun getElement(row: Int, column: Int) = matrix[row][column]

    fun getB(index: Int): Double {
        return if (index >= 0 && index < matrix.size - 1) {
            matrix[index][index + 1]
        } else {
            error("b index is wrong")
            0.0
        }
    }

    fun getC(index: Int): Double {
        return if (index >= 0 && index < matrix.size) {
            matrix[index][index]
        } else {
            error("c index is wrong")
            0.0
        }
    }

    fun getA(index: Int): Double {
        return if (index >= 1 && index < matrix.size) {
            matrix[index][index - 1]
        } else {
            error("alpha index is wrong")
            0.0
        }
    }


    fun printMatrix() {
        println(matrix.size)
//        matrix.forEach { println("[ ${it.forEach { value -> print("$value ,") }} ]") }
        for (element in matrix) {
            println(element.contentToString())
        }
    }
}