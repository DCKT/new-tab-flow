const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const outputDir = path.join(__dirname, 'build/')

const isProd = process.env.NODE_ENV === 'production'

module.exports = {
  entry: './src/App.bs.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'App.bs.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/html/override.html',
      inject: false,
      filename: 'override.html'
    }),
    new HtmlWebpackPlugin({
      template: 'src/html/options.html',
      inject: false,
      filename: 'options.html'
    }),
    new HtmlWebpackPlugin({
      template: 'src/html/background.html',
      inject: false,
      filename: 'background.html'
    })
  ],
  optimization: {
    usedExports: true
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  }
}
