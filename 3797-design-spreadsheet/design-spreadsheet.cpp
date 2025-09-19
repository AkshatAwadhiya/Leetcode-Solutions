class Spreadsheet {
private:
    int numRows;
    unordered_map<string, int> cells;    
    int getCellValue(const string& cellRef) {
        if (cells.find(cellRef) != cells.end()) {
            return cells[cellRef];
        }
        return 0;
    }    
    bool isNumber(const string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }    
    int parseOperand(const string& operand) {
        if (isNumber(operand)) {
            return stoi(operand);
        } else {
            return getCellValue(operand);
        }
    }
    
public:
    Spreadsheet(int rows) : numRows(rows) {
    }
    
    void setCell(string cell, int value) {
        if (value == 0) {
            cells.erase(cell);
        } else {
            cells[cell] = value;
        }
    }
    
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    int getValue(string formula) {
        string expr = formula.substr(1);
        
        size_t plusPos = expr.find('+');        
        string leftOperand = expr.substr(0, plusPos);
        string rightOperand = expr.substr(plusPos + 1);        
        int leftValue = parseOperand(leftOperand);
        int rightValue = parseOperand(rightOperand);
        
        return leftValue + rightValue;
    }
};