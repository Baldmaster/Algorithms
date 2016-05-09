class Vertex {
  constructor(label) {
    this.label = label 
    this.adjacent = new Set()
  }
  addAdjacent(vertex) { this.adjacent.add(vertex) }
}

class Graph {
  constructor() {
    this.vertices = new Map()
    this.dfs = dfsIterative
  }
  addEdge(v, w, d = true) {
    let vert = this.vertices
    
    vert.has(v.label) || vert.set(v.label, v)
    vert.has(w.label) || vert.set(w.label, w)
    
    vert.get(v.label).addAdjacent(w)

    //if edge is not directed
    if (!d) {
      vert.get(w.label).addAdjacent(v)
    }
  } 
}

function dfsIterative(vertex) {
  let visited = new Set()
  let stack = []
  var current
  
  stack.push(vertex)

  while(stack.length) {
    current = stack.pop()
    if (! visited.has(current.label)) {
      visited.add(current.label)
      console.log(current.label, ' -> ')
      for (let v of current.adjacent) {
        stack.push(v)
      }
    }
  }
}


module.exports = {
  Vertex: Vertex,
  Graph: Graph
}
