<h1 align="center">
  <img src="https://github.com/senthilpoo10/badges/blob/main/badges/fractolm.png" width="200"/>
</h1>

<p align="center">
  <b><i>Computer Graphics Fractals Explorer</i></b><br>
  <i>"Discover infinite complexity at every scale"</i>
</p>

<p align="center">
  <img alt="score" src="https://img.shields.io/badge/score-125%2F100-brightgreen" />
  <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
  <img alt="time spent" src="https://img.shields.io/badge/time%20spent-50%20hours-blue" />
  <img alt="XP earned" src="https://img.shields.io/badge/XP%20earned-312-orange" />
<p align="center">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/coding-school-projects/fractol?color=lightblue" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/coding-school-projects/fractol?color=blue" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/coding-school-projects/fractol?color=green" />
</p>

## 📚 About The Project

fract'ol is a 42 School project that renders beautiful mathematical fractals in real-time using the MiniLibX graphics library. This project explores complex number mathematics and computer graphics optimization while creating infinitely zoomable fractal visualizations.

**Key Features:**
- Mandelbrot and Julia set visualizations
- Smooth infinite zoom (mouse wheel)
- Interactive parameter control
- Psychedelic color schemes
- Bonus: Burning Ship fractal, mouse-follow zoom, and color shifting

## 🏁 Getting Started

### 🛠️ Installation & Usage

1. Clone the repository:
```bash
git clone https://github.com/coding-school-projects/fractol.git
cd fractol
```

2. Compile the project:
```bash
make
```

3. Run with a fractal type:
```bash
./fractol mandelbrot
./fractol julia -0.7 0.27
./fractol burning_ship  # Bonus
```

### 🎮 Controls
| Key/Mouse | Action |
|-----------|--------|
| Mouse Wheel | Zoom in/out |
| ESC | Quit program |
| Arrow Keys | Move view (bonus) |
| C | Cycle color schemes |
| R | Reset view |
| Space | Toggle mouse follow (bonus) |

## 🧠 Technical Implementation

### Core Algorithms
| Fractal | Formula | Implementation |
|---------|---------|----------------|
| Mandelbrot | zₙ₊₁ = zₙ² + c | Complex plane iteration |
| Julia | zₙ₊₁ = zₙ² + k | Fixed parameter k |
| Burning Ship | zₙ₊₁ = (|Re(zₙ)| + i|Im(zₙ)|)² + c | Absolute value variant |

### Performance Optimizations
- Multi-threaded rendering (4 threads)
- Optimized complex number calculations
- Adaptive iteration counts based on zoom level
- Smooth color gradient interpolation

## 🧪 Testing Protocol

1. Basic rendering test:
```bash
./fractol mandelbrot
```

2. Julia set with parameters:
```bash
./fractol julia -0.4 0.6
```

3. Stress test (deep zoom):
```bash
./fractol mandelbrot
# Zoom 20+ times with mouse wheel
```

4. Bonus features:
```bash
./fractol burning_ship
# Test arrow keys and color cycling
```

## 📝 Evaluation Criteria

1. **Correctness**: Accurate fractal rendering
2. **Performance**: Smooth zooming/panning
3. **Features**: Mandatory + bonus implementations
4. **Code Quality**: No leaks, norm compliant
5. **Error Handling**: Graceful exit on invalid input

### 🧑‍💻 Peer Evaluations (3/3)

> **Peer 1**: "Very well done project. All bonuses done, no leaks or errors could be found. Code is easy to read and understand. Overall great job!"

> **Peer 2**: "Poonkodi made really great work!! It was really nice frat-ol and her code all worked as expected. We tested her mandatory's two fract-ols and for bonus the 'burning ship' also. all images showed very nice colour with well writen code. I didn't do this project but it was very interesting to see the project and it was really fun time with her. Thanks for the nice time and evaluation. Have a good day and good luck for the next project as well :)"

> **Peer 3**: "Amazing work Poonkodi, it was a nice and easy evaluation, I was able to follow the flow of your code, and you were able to lead me along with answers to all my questions. You even did all the bonus part. that is great work. well done and thank you!"


