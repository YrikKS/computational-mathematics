data class RunThroughMethod(val matrix: Matrix, val vectorF: Vector) {
    private var vectorResult = Vector(vectorF.getSize()) { 0.0 }
    private var vectorAlpha = Vector(vectorF.getSize()) { 0.0 }
    private var vectorBeta = Vector(vectorF.getSize()) { 0.0 }

    fun startMethod(): Vector {
        calculateAlphaAndBeta()
        calculateX()
//        vectorResult.printVector()
        return vectorResult
    }

    private fun calculateX() {
        val calculateX: (Int) -> Double = {
            vectorAlpha.getElement(it) * vectorResult.getElement(it + 1) + vectorBeta.getElement(it)
        }
        vectorResult.setElement(vectorResult.getSize() - 1, vectorBeta.getElement(vectorResult.getSize() - 1))
        for (index in (vectorF.getSize() - 2) downTo 0) {
            vectorResult.setElement(index, calculateX(index))
        }
    }

    private fun calculateAlphaAndBeta() {
        vectorAlpha.setElement(0, matrix.getB(0) / matrix.getC(0))
        vectorBeta.setElement(0, vectorF.getElement(0) / matrix.getC(0))
        val calculateAlpha: (Int) -> Double = {
            matrix.getB(it) / (matrix.getC(it) - (matrix.getA(it) * vectorAlpha.getElement(it - 1)))
        }
        val calculateBeta: (Int) -> Double = {
            (vectorF.getElement(it) + matrix.getA(it) * vectorBeta.getElement(it - 1)) / (matrix.getC(it) -
                    (matrix.getA(it) * vectorAlpha.getElement(it - 1)))
        }
        for (index in 1 until vectorF.getSize()) {
            if (index != vectorF.getSize() - 1)
                vectorAlpha.setElement(index, calculateAlpha(index))
            vectorBeta.setElement(index, calculateBeta(index))
        }
//        vectorAlpha.printVector()
//        vectorBeta.printVector()
    }
}