def diagonal_sum(mat)
    primary_diagonal_sum = (0...mat.size).map { |i| mat[i][i] }.sum
    secondary_diagonal_sum = (0...mat.size).map { |i| mat[i][mat.size-i-1] }.sum
    return primary_diagonal_sum + secondary_diagonal_sum - mat[mat.size/2][mat.size/2] if mat.size.odd?
    primary_diagonal_sum + secondary_diagonal_sum
end
